/*****************************************************************************
* Copyright (c) 2008-2012 Sergey Radionov <rsatom_gmail.com>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of the Sergey Radionov aka RSATom nor the
*       names of project contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#if !defined(L_SSLCONTEXT_H)
#define L_SSLCONTEXT_H

#include "SockByteStream.h"

#include <vector>

#ifndef SECURITY_WIN32
#	define SECURITY_WIN32 1
#	include <security.h>
#endif

class LSSLContext
{
public:
	LSSLContext();
	~LSSLContext();

	void AcquireCredentials();
	void Handshake(LSockByteStream* SockByteStream, const TCHAR* TargetName);
	void Shutdown(LSockByteStream* SockByteStream, const TCHAR* TargetName);

	CtxtHandle* GetContextHandle() {return &m_hContext;}

	const std::vector<BYTE>& GetHandshakeExtra() const {return m_HandshakeExtra;};

private:
	ULONG m_ReqContextAttr;
	CredHandle m_hUserCred;
	TimeStamp  m_UserCredExpiry;

	CtxtHandle m_hContext;
	TimeStamp  m_ContextExpiry;
	ULONG m_ContextAttr;

	std::vector<BYTE> m_HandshakeExtra;
};

#endif //L_SSLCONTEXT_H
