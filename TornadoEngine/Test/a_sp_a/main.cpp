#include "SynchroAbonent.h"
#include "SynchroPoint.h"
#include "ContainerTypes.h"

#define NUM_GE  0
#define NUM_PE  1
#define NUM_SE  2

int main(int argc, char** argv)
{
  TSynchroAbonent GE, PE, SE;
  TSynchroPoint* pSP = new TSynchroPoint;

  GE.SetSynchroPoint(pSP);
  GE.SetSelfID(NUM_GE);
  GE.Register(NUM_PE);

  SE.SetSynchroPoint(pSP);
  SE.SetSelfID(NUM_SE);
  SE.Register(NUM_PE);

  PE.SetSynchroPoint(pSP);
  PE.SetSelfID(NUM_PE);
  PE.Register(NUM_GE);
  
  //char eventGE[] = {0x1,};
  //GE.AddEventCopy( &eventGE[0], sizeof(eventGE));
  //TContainer* pEvent1 = PE.GetEvent(NUM_GE);

  char eventPE[] = {0x2,};
  PE.AddEventWithoutCopy( &eventPE[0], sizeof(eventPE));

  TContainer* pEventGE = GE.GetEvent(NUM_PE);
  char* pGE  = pEventGE->GetPtr();
  int sizeGE = pEventGE->GetSize();

  TContainer* pEventSE = SE.GetEvent(NUM_PE);
  char* pSE  = pEventSE->GetPtr();
  int sizeSE = pEventSE->GetSize();

  return 0;
}