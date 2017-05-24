#include "Interface.h"
#include "SpinBox.h"

rts::SpinBox::SpinBox(MyGUI::EditBox* edit_box, MyGUI::Button* spin_up, MyGUI::Button* spin_down,
                      uint32_t spin_slow, uint32_t spin_fast, int64_t* value) :
                        m_edit_box(edit_box),
                        m_spin_up(spin_up),
                        m_spin_down(spin_down),
                        m_spin_slow_amount(spin_slow),
                        m_spin_fast_amount(spin_fast),
                        m_spin_fast_delay(2000), //2 sec delay before kicking fast spin
                        m_spin_time(0.0),
                        m_spin_tick_rate(250), //increment 4 times a second by default
                        m_time_since_last_tick(static_cast<double>(m_spin_tick_rate)),
                        m_incrementing(false),
                        m_decrementing(false),
                        m_min_spin_val(0),
                        m_max_spin_val(100),
                        m_value(value)
{
    //register myself with interface so I can work properly
    Interface::getSingletonPtr()->registerSpinBox(this); 

    //passing value as user data to edit box
    m_edit_box->setUserData(value);

    //setting up mouse responses to presses
    m_spin_up->eventMouseButtonPressed = MyGUI::newDelegate(this, &SpinBox::onIncrementPressed);
    m_spin_up->eventMouseButtonReleased = MyGUI::newDelegate(this, &SpinBox::onIncrementReleased);
    m_spin_up->eventMouseLostFocus = MyGUI::newDelegate(this, &SpinBox::onFocusLost);
                                                      
    m_spin_down->eventMouseButtonPressed = MyGUI::newDelegate(this, &SpinBox::onDecrementPressed);
    m_spin_down->eventMouseButtonReleased = MyGUI::newDelegate(this, &SpinBox::onDecrementReleased);
    m_spin_down->eventMouseLostFocus = MyGUI::newDelegate(this, &SpinBox::onFocusLost);

    //setting up response to scroll wheel
    
    m_edit_box->eventMouseWheel = MyGUI::newDelegate(this, &SpinBox::onScroll); //why not working?
    m_spin_up->eventMouseWheel = MyGUI::newDelegate(this, &SpinBox::onScroll);
    m_spin_down->eventMouseWheel = MyGUI::newDelegate(this, &SpinBox::onScroll);

    //setting up limits for manual typing
    m_edit_box->eventEditTextChange += MyGUI::newDelegate(this, &SpinBox::onFormatInput);
    m_edit_box->eventEditSelectAccept += MyGUI::newDelegate(this, &SpinBox::onAcceptInput);
    
    updateEditBoxValue();
}

rts::SpinBox::~SpinBox()
{
    //remove myself from interface so I won't cause problems
    Interface::getSingletonPtr()->unregisterSpinBox(this);
}

void rts::SpinBox::updateSpinValues(uint32_t spin_slow, uint32_t spin_fast)
{
    m_spin_slow_amount = spin_slow;
    m_spin_fast_amount = spin_fast;
}

void rts::SpinBox::setFastSpinDelay(uint32_t fast_spin_delay_in_ms)
{
    m_spin_fast_delay = fast_spin_delay_in_ms;
}

void rts::SpinBox::setSpinTickRate(uint32_t spin_rate)
{
    m_spin_tick_rate = spin_rate;
}

void rts::SpinBox::setSpinLimits(int spin_min_val, int spin_max_val)
{
    m_min_spin_val = spin_min_val;
    m_max_spin_val = spin_max_val;
}

void rts::SpinBox::onIncrementPressed(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button)
{
    if(mouse_button == MyGUI::MouseButton::Left){
        //button has been pressed, we increment the value
        *m_value += m_spin_slow_amount;
        verifyValue();
        updateEditBoxValue();

        //followed by starting the counters
        m_incrementing = true;
        m_spin_time = 0;
        m_time_since_last_tick = 0;
        //can't do both at the same time
        m_decrementing = false;
    }
}

void rts::SpinBox::onIncrementReleased(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button)
{
    if(mouse_button == MyGUI::MouseButton::Left){
        m_incrementing = false;
        m_spin_time = 0;
        m_time_since_last_tick = 0;
    }
}

void rts::SpinBox::onDecrementPressed(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button)
{
    if(mouse_button == MyGUI::MouseButton::Left){
        //button has been pressed, we decrement the value
        *m_value -= m_spin_slow_amount;
        verifyValue();
        updateEditBoxValue();

        //followed by starting the counting
        m_decrementing = true;
        m_spin_time = 0;
        m_time_since_last_tick = 0;
        //can't do both at the same time
        m_incrementing = false;
    }
}

void rts::SpinBox::onDecrementReleased(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button)
{
    if(mouse_button == MyGUI::MouseButton::Left){
        m_decrementing = false;
        m_spin_time = 0;
        m_time_since_last_tick = 0;
    }
}
void rts::SpinBox::onFocusLost(MyGUI::Widget* _widget1, MyGUI::Widget* _widget2)
{
    m_incrementing = false;
    m_decrementing = false;
    m_spin_time = 0;
    m_time_since_last_tick = 0;
}

void rts::SpinBox::onAcceptInput(MyGUI::Widget* _widget)
{
    utility::ston(_widget->castType<MyGUI::EditBox>()->getCaption(), *m_value);
    verifyValue();
    updateEditBoxValue();
}

void rts::SpinBox::onFormatInput(MyGUI::Widget* _widget)
{
    //go through the string, check for non-digit values and remove them
    MyGUI::UString s = m_edit_box->getCaption();
    for(size_t i = 0; i < s.size(); ++i){
        if(!std::isdigit(s[i])){
            s.erase(i, 1);
            --i;
        }
    }
    m_edit_box->setCaption(s);
}

void rts::SpinBox::onScroll(MyGUI::Widget* _widget, int val)
{
    if(val < 0){
        *m_value -= m_spin_slow_amount;
    }
    else if(val > 0){
        *m_value += m_spin_slow_amount;
    }
    //verify and update
    verifyValue();
    updateEditBoxValue();
}

MyGUI::EditBox* rts::SpinBox::getEditBox()
{
    return m_edit_box;
}

MyGUI::Button* rts::SpinBox::getSpinUpButton()
{
    return m_spin_up;
}

MyGUI::Button* rts::SpinBox::getSpinDownButton()
{
    return m_spin_down;
}

void rts::SpinBox::tickUpdate(double frame_time)
{
    //only update when main edit box is visible
    if(m_edit_box->getVisible()){
        //if it's time to tick
        if((m_incrementing || m_decrementing)){

            //always add time when spinning, 
            m_spin_time += frame_time;
            m_time_since_last_tick += frame_time;

            //but only tick when we should            
            if(m_time_since_last_tick >= static_cast<double>(m_spin_tick_rate)){

                if(m_incrementing){
                    
                    if(m_spin_time >= static_cast<double>(m_spin_fast_delay)){
                        *m_value += m_spin_fast_amount;
                    }
                    else{
                        *m_value += m_spin_slow_amount;
                    }

                }
                else if(m_decrementing){

                    if(m_spin_time >= static_cast<double>(m_spin_fast_delay)){
                        *m_value -= m_spin_fast_amount;
                    }
                    else{
                        *m_value -= m_spin_slow_amount;
                    }

                }

                //verify and update value
                verifyValue();
                updateEditBoxValue();

                //subtract spin rate, leave remaining time for accuracy
                m_time_since_last_tick -= m_spin_tick_rate; 
            }
        }
    }
}

void rts::SpinBox::updateEditBoxValue()
{

    m_edit_box->setCaption(utility::ntos(*m_value));
}

void rts::SpinBox::verifyValue()
{
    //check against min/max set 
    if(*m_value < static_cast<int64_t>(m_min_spin_val))
        *m_value = m_min_spin_val;
    else if(*m_value > static_cast<int64_t>(m_max_spin_val))
        *m_value = m_max_spin_val;
}