#ifndef PCS_IHandlerH
#define PCS_IHandlerH

class PCS_IHandler
{
public:
  PCS_IHandler();
  virtual ~PCS_IHandler() = 0;

  void Setup();
  void Send();
};
#endif