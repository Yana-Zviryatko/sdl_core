/**
* Copyright (c) 2014, Ford Motor Company
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following
* disclaimer in the documentation and/or other materials provided with the
* distribution.
*
* Neither the name of the Ford Motor Company nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef TYPE_BASE_H_
#define TYPE_BASE_H_

#include "rpc_base.h"

namespace Json {
class Value;
}

namespace rpc {

enum MessageType {
  kRequest = 0,
  kResponse = 1,
  kNotification = 2
};

class Message : public CompositeType {
public:
  virtual MessageType message_type() const = 0;
  virtual int32_t function_id() const = 0;
  virtual const char* function_string_id() const = 0;
  virtual Json::Value ToJsonValue() const = 0;
  virtual ~Message() {}
};

class RequestBase : public Message {
 public:
  MessageType message_type() const { return kRequest; }
  virtual ~RequestBase() {}
};

class ResponseBase : public Message {
 public:
  MessageType message_type() const { return kResponse; }
  virtual ~ResponseBase() {}
};

class NotificationBase : public Message {
 public:
  MessageType message_type() const { return kNotification; }
  virtual ~NotificationBase() {}
};

}  // namespace rpc

#endif /* TYPE_BASE_H_ */
