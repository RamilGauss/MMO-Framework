namespace DotNET_MMOEngineWrapper
{
  unsafe interface IClient
  {
    void Login( uint ip, ushort port, 
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword);

    void LeaveQueue();
  }
}
