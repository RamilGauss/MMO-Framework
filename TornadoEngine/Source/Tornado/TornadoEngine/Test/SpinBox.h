#ifndef UISPINBOX_H
#define UISPINBOX_H

#include <MyGUI.h>

namespace rts
{
    //utility class that wraps 3 widgets of your choice to work as a spinner control/spinbox
    //adjust fast sping delay with setFastSpinDelay - 2000ms default
    //adjust min/max values with setSpinLimits - 0-100 default
    //adjust tick rate with setSpinTickRate - 250ms default
    class SpinBox
    {
    public:
        //standard constructor
        //edit_box is where value will be displayed
        //spin_up is the up arrow/increment button
        //spin_down is the down arrow/decrement button
        //spin_slow is the amount to change with each click
        //spin_fast is the amount to change after holding for set period of time 
        //value is the pointer to integer that the spinbox controls
        SpinBox(MyGUI::EditBox* edit_box, MyGUI::Button* spin_up, MyGUI::Button* spin_down, uint32_t spin_slow, uint32_t spin_fast, int64_t* value);
        ~SpinBox();
        void    updateSpinValues(uint32_t spin_slow, uint32_t spin_fast);
        void    setFastSpinDelay(uint32_t fast_spin_delay_in_ms);
        void    setSpinTickRate(uint32_t spin_rate);
        void    setSpinLimits(int spin_min_val, int spin_max_val);

        void    onIncrementPressed(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button);
        void    onIncrementReleased(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button);
        void    onDecrementPressed(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button);
        void    onDecrementReleased(MyGUI::Widget* _widget, int x, int y, MyGUI::MouseButton mouse_button);
        void    onFocusLost(MyGUI::Widget* _widget1, MyGUI::Widget* _widget2);
        void    onAcceptInput(MyGUI::Widget* _widget);
        void    onFormatInput(MyGUI::Widget* _widget);
        void    onScroll(MyGUI::Widget* _widget, int val);
        
        MyGUI::EditBox* getEditBox();
        MyGUI::Button*  getSpinUpButton();
        MyGUI::Button*  getSpinDownButton();

        //needs to be called periodically for spinner to work
        void    tickUpdate(double frame_time);

    protected:
        void    updateEditBoxValue();
        void    verifyValue();

        //pointers to interface elements
        MyGUI::EditBox*     m_edit_box;
        MyGUI::Button*      m_spin_up;
        MyGUI::Button*      m_spin_down;

        //value control
        uint32_t            m_spin_slow_amount;
        uint32_t            m_spin_fast_amount;
        int                 m_min_spin_val;
        int                 m_max_spin_val;

        //change rates
        uint64_t            m_spin_fast_delay;
        double              m_spin_time;
        uint64_t            m_spin_tick_rate;
        double              m_time_since_last_tick;

        int64_t*            m_value;

        //arrow changes
        bool                m_incrementing;
        bool                m_decrementing;
    };
}

#endif //UISPINBOX_H

