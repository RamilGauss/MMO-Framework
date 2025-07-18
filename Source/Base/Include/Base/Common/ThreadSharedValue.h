#pragma once

class TThreadSharedValue
{
    std::atomic_bool mIsRequest
    std::atomic_bool mIsResponse;

public:
    // From request thread
    void SetRequest()
    {
        mIsRequest = true;
    }
    bool IsReadyResponse()
    {
        if (mIsResponse) {
            mIsRequest = false;
            while (not IsNeedResponse()) {}
            return true;
        }
        return false;
    }
    // From response thread
    void SetResponse()
    {
        mIsResponse = true;
        while (IsNeedResponse()) {}
        mIsResponse = false;
    }
    bool IsNeedResponse() const
    {
        return mIsRequest;
    }
};

class TThreadSharedValue
{
    std::atomic_bool mIsRequest
    std::mutex mMutex;
public:
    // From request thread
    void SetRequest(bool value)
    {
        std::lock_guard<std::mutex> guard(mMutex);
        mIsRequest = value;
    }
    bool GetRequest() const
    {
        return mIsRequest;
    }
};

// thread #0
SaveVar();// and flush CPU cache
SetRequest(true)
ResumeThread();
while (mSharedValue.GetRequest()) {}

// thread #1
if (mSharedValue.GetRequest()) {
    // invalidate CPU cache
    GetVar();
    SetRequest(true)
}
