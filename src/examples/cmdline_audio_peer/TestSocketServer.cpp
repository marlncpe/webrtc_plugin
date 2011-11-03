//
//  TestSocketServer.cpp
//  TestPeerConnectionClient
//
//  Created by Manjesh Malavalli on 10/18/11.
//  Copyright 2011 XVDTH. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "TestSocketServer.h"
#include "TestDefaults.h"

TestSocketServer::TestSocketServer():
m_pThread(talk_base::Thread::Current()),
m_pClient(NULL)
{

}

TestSocketServer::~TestSocketServer()
{
    
}

void TestSocketServer::SetTestPeerConnectionClient(TestPeerConnectionClient *pClient)
{
    ASSERT(NULL == m_pClient);
    m_pClient = pClient;
}

bool TestSocketServer::Wait(int cms, bool process_io)
{
    ASSERT(NULL != m_pThread);
    
    bool bStatus = m_pClient->ExecuteNextCommand();    
    if(false == bStatus)
    {
        //error
        ;
    }
    
    return talk_base::PhysicalSocketServer::Wait(1000, process_io);
}
