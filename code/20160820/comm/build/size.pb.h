// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: size.proto

#ifndef PROTOBUF_size_2eproto__INCLUDED
#define PROTOBUF_size_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_size_2eproto();
void protobuf_AssignDesc_size_2eproto();
void protobuf_ShutdownFile_size_2eproto();

class DyMsg;
class Size;

// ===================================================================

class Size : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Size) */ {
 public:
  Size();
  virtual ~Size();

  Size(const Size& from);

  inline Size& operator=(const Size& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Size& default_instance();

  void Swap(Size* other);

  // implements Message ----------------------------------------------

  inline Size* New() const { return New(NULL); }

  Size* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Size& from);
  void MergeFrom(const Size& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Size* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 length = 1;
  void clear_length();
  static const int kLengthFieldNumber = 1;
  ::google::protobuf::int32 length() const;
  void set_length(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Size)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 length_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_size_2eproto();
  friend void protobuf_AssignDesc_size_2eproto();
  friend void protobuf_ShutdownFile_size_2eproto();

  void InitAsDefaultInstance();
  static Size* default_instance_;
};
// -------------------------------------------------------------------

class DyMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:DyMsg) */ {
 public:
  DyMsg();
  virtual ~DyMsg();

  DyMsg(const DyMsg& from);

  inline DyMsg& operator=(const DyMsg& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DyMsg& default_instance();

  void Swap(DyMsg* other);

  // implements Message ----------------------------------------------

  inline DyMsg* New() const { return New(NULL); }

  DyMsg* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DyMsg& from);
  void MergeFrom(const DyMsg& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(DyMsg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string topic = 1;
  void clear_topic();
  static const int kTopicFieldNumber = 1;
  const ::std::string& topic() const;
  void set_topic(const ::std::string& value);
  void set_topic(const char* value);
  void set_topic(const char* value, size_t size);
  ::std::string* mutable_topic();
  ::std::string* release_topic();
  void set_allocated_topic(::std::string* topic);

  // optional string tag = 2;
  void clear_tag();
  static const int kTagFieldNumber = 2;
  const ::std::string& tag() const;
  void set_tag(const ::std::string& value);
  void set_tag(const char* value);
  void set_tag(const char* value, size_t size);
  ::std::string* mutable_tag();
  ::std::string* release_tag();
  void set_allocated_tag(::std::string* tag);

  // optional string key = 3;
  void clear_key();
  static const int kKeyFieldNumber = 3;
  const ::std::string& key() const;
  void set_key(const ::std::string& value);
  void set_key(const char* value);
  void set_key(const char* value, size_t size);
  ::std::string* mutable_key();
  ::std::string* release_key();
  void set_allocated_key(::std::string* key);

  // optional string body = 4;
  void clear_body();
  static const int kBodyFieldNumber = 4;
  const ::std::string& body() const;
  void set_body(const ::std::string& value);
  void set_body(const char* value);
  void set_body(const char* value, size_t size);
  ::std::string* mutable_body();
  ::std::string* release_body();
  void set_allocated_body(::std::string* body);

  // optional string timestamp = 5;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 5;
  const ::std::string& timestamp() const;
  void set_timestamp(const ::std::string& value);
  void set_timestamp(const char* value);
  void set_timestamp(const char* value, size_t size);
  ::std::string* mutable_timestamp();
  ::std::string* release_timestamp();
  void set_allocated_timestamp(::std::string* timestamp);

  // @@protoc_insertion_point(class_scope:DyMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr topic_;
  ::google::protobuf::internal::ArenaStringPtr tag_;
  ::google::protobuf::internal::ArenaStringPtr key_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  ::google::protobuf::internal::ArenaStringPtr timestamp_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_size_2eproto();
  friend void protobuf_AssignDesc_size_2eproto();
  friend void protobuf_ShutdownFile_size_2eproto();

  void InitAsDefaultInstance();
  static DyMsg* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Size

// optional int32 length = 1;
inline void Size::clear_length() {
  length_ = 0;
}
inline ::google::protobuf::int32 Size::length() const {
  // @@protoc_insertion_point(field_get:Size.length)
  return length_;
}
inline void Size::set_length(::google::protobuf::int32 value) {
  
  length_ = value;
  // @@protoc_insertion_point(field_set:Size.length)
}

// -------------------------------------------------------------------

// DyMsg

// optional string topic = 1;
inline void DyMsg::clear_topic() {
  topic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DyMsg::topic() const {
  // @@protoc_insertion_point(field_get:DyMsg.topic)
  return topic_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_topic(const ::std::string& value) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DyMsg.topic)
}
inline void DyMsg::set_topic(const char* value) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DyMsg.topic)
}
inline void DyMsg::set_topic(const char* value, size_t size) {
  
  topic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DyMsg.topic)
}
inline ::std::string* DyMsg::mutable_topic() {
  
  // @@protoc_insertion_point(field_mutable:DyMsg.topic)
  return topic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DyMsg::release_topic() {
  // @@protoc_insertion_point(field_release:DyMsg.topic)
  
  return topic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_allocated_topic(::std::string* topic) {
  if (topic != NULL) {
    
  } else {
    
  }
  topic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), topic);
  // @@protoc_insertion_point(field_set_allocated:DyMsg.topic)
}

// optional string tag = 2;
inline void DyMsg::clear_tag() {
  tag_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DyMsg::tag() const {
  // @@protoc_insertion_point(field_get:DyMsg.tag)
  return tag_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_tag(const ::std::string& value) {
  
  tag_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DyMsg.tag)
}
inline void DyMsg::set_tag(const char* value) {
  
  tag_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DyMsg.tag)
}
inline void DyMsg::set_tag(const char* value, size_t size) {
  
  tag_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DyMsg.tag)
}
inline ::std::string* DyMsg::mutable_tag() {
  
  // @@protoc_insertion_point(field_mutable:DyMsg.tag)
  return tag_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DyMsg::release_tag() {
  // @@protoc_insertion_point(field_release:DyMsg.tag)
  
  return tag_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_allocated_tag(::std::string* tag) {
  if (tag != NULL) {
    
  } else {
    
  }
  tag_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), tag);
  // @@protoc_insertion_point(field_set_allocated:DyMsg.tag)
}

// optional string key = 3;
inline void DyMsg::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DyMsg::key() const {
  // @@protoc_insertion_point(field_get:DyMsg.key)
  return key_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_key(const ::std::string& value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DyMsg.key)
}
inline void DyMsg::set_key(const char* value) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DyMsg.key)
}
inline void DyMsg::set_key(const char* value, size_t size) {
  
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DyMsg.key)
}
inline ::std::string* DyMsg::mutable_key() {
  
  // @@protoc_insertion_point(field_mutable:DyMsg.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DyMsg::release_key() {
  // @@protoc_insertion_point(field_release:DyMsg.key)
  
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    
  } else {
    
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:DyMsg.key)
}

// optional string body = 4;
inline void DyMsg::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DyMsg::body() const {
  // @@protoc_insertion_point(field_get:DyMsg.body)
  return body_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DyMsg.body)
}
inline void DyMsg::set_body(const char* value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DyMsg.body)
}
inline void DyMsg::set_body(const char* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DyMsg.body)
}
inline ::std::string* DyMsg::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:DyMsg.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DyMsg::release_body() {
  // @@protoc_insertion_point(field_release:DyMsg.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:DyMsg.body)
}

// optional string timestamp = 5;
inline void DyMsg::clear_timestamp() {
  timestamp_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DyMsg::timestamp() const {
  // @@protoc_insertion_point(field_get:DyMsg.timestamp)
  return timestamp_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_timestamp(const ::std::string& value) {
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DyMsg.timestamp)
}
inline void DyMsg::set_timestamp(const char* value) {
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DyMsg.timestamp)
}
inline void DyMsg::set_timestamp(const char* value, size_t size) {
  
  timestamp_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DyMsg.timestamp)
}
inline ::std::string* DyMsg::mutable_timestamp() {
  
  // @@protoc_insertion_point(field_mutable:DyMsg.timestamp)
  return timestamp_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DyMsg::release_timestamp() {
  // @@protoc_insertion_point(field_release:DyMsg.timestamp)
  
  return timestamp_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DyMsg::set_allocated_timestamp(::std::string* timestamp) {
  if (timestamp != NULL) {
    
  } else {
    
  }
  timestamp_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), timestamp);
  // @@protoc_insertion_point(field_set_allocated:DyMsg.timestamp)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_size_2eproto__INCLUDED
