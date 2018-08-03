// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: events.proto

#ifndef PROTOBUF_events_2eproto__INCLUDED
#define PROTOBUF_events_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_events_2eproto();
void protobuf_AssignDesc_events_2eproto();
void protobuf_ShutdownFile_events_2eproto();

class Event;
class Events;

// ===================================================================

class Event : public ::google::protobuf::Message {
 public:
  Event();
  virtual ~Event();

  Event(const Event& from);

  inline Event& operator=(const Event& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Event& default_instance();

  void Swap(Event* other);

  // implements Message ----------------------------------------------

  Event* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Event& from);
  void MergeFrom(const Event& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int64 timestamp = 1;
  inline bool has_timestamp() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  inline ::google::protobuf::int64 timestamp() const;
  inline void set_timestamp(::google::protobuf::int64 value);

  // optional string userId = 2;
  inline bool has_userid() const;
  inline void clear_userid();
  static const int kUserIdFieldNumber = 2;
  inline const ::std::string& userid() const;
  inline void set_userid(const ::std::string& value);
  inline void set_userid(const char* value);
  inline void set_userid(const char* value, size_t size);
  inline ::std::string* mutable_userid();
  inline ::std::string* release_userid();
  inline void set_allocated_userid(::std::string* userid);

  // optional string eventDescription = 3;
  inline bool has_eventdescription() const;
  inline void clear_eventdescription();
  static const int kEventDescriptionFieldNumber = 3;
  inline const ::std::string& eventdescription() const;
  inline void set_eventdescription(const ::std::string& value);
  inline void set_eventdescription(const char* value);
  inline void set_eventdescription(const char* value, size_t size);
  inline ::std::string* mutable_eventdescription();
  inline ::std::string* release_eventdescription();
  inline void set_allocated_eventdescription(::std::string* eventdescription);

  // @@protoc_insertion_point(class_scope:Event)
 private:
  inline void set_has_timestamp();
  inline void clear_has_timestamp();
  inline void set_has_userid();
  inline void clear_has_userid();
  inline void set_has_eventdescription();
  inline void clear_has_eventdescription();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int64 timestamp_;
  ::std::string* userid_;
  ::std::string* eventdescription_;
  friend void  protobuf_AddDesc_events_2eproto();
  friend void protobuf_AssignDesc_events_2eproto();
  friend void protobuf_ShutdownFile_events_2eproto();

  void InitAsDefaultInstance();
  static Event* default_instance_;
};
// -------------------------------------------------------------------

class Events : public ::google::protobuf::Message {
 public:
  Events();
  virtual ~Events();

  Events(const Events& from);

  inline Events& operator=(const Events& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Events& default_instance();

  void Swap(Events* other);

  // implements Message ----------------------------------------------

  Events* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Events& from);
  void MergeFrom(const Events& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Event events = 1;
  inline int events_size() const;
  inline void clear_events();
  static const int kEventsFieldNumber = 1;
  inline const ::Event& events(int index) const;
  inline ::Event* mutable_events(int index);
  inline ::Event* add_events();
  inline const ::google::protobuf::RepeatedPtrField< ::Event >&
      events() const;
  inline ::google::protobuf::RepeatedPtrField< ::Event >*
      mutable_events();

  // @@protoc_insertion_point(class_scope:Events)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Event > events_;
  friend void  protobuf_AddDesc_events_2eproto();
  friend void protobuf_AssignDesc_events_2eproto();
  friend void protobuf_ShutdownFile_events_2eproto();

  void InitAsDefaultInstance();
  static Events* default_instance_;
};
// ===================================================================


// ===================================================================

// Event

// optional int64 timestamp = 1;
inline bool Event::has_timestamp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Event::set_has_timestamp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Event::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Event::clear_timestamp() {
  timestamp_ = GOOGLE_LONGLONG(0);
  clear_has_timestamp();
}
inline ::google::protobuf::int64 Event::timestamp() const {
  // @@protoc_insertion_point(field_get:Event.timestamp)
  return timestamp_;
}
inline void Event::set_timestamp(::google::protobuf::int64 value) {
  set_has_timestamp();
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:Event.timestamp)
}

// optional string userId = 2;
inline bool Event::has_userid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Event::set_has_userid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Event::clear_has_userid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Event::clear_userid() {
  if (userid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_->clear();
  }
  clear_has_userid();
}
inline const ::std::string& Event::userid() const {
  // @@protoc_insertion_point(field_get:Event.userId)
  return *userid_;
}
inline void Event::set_userid(const ::std::string& value) {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  userid_->assign(value);
  // @@protoc_insertion_point(field_set:Event.userId)
}
inline void Event::set_userid(const char* value) {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  userid_->assign(value);
  // @@protoc_insertion_point(field_set_char:Event.userId)
}
inline void Event::set_userid(const char* value, size_t size) {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  userid_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Event.userId)
}
inline ::std::string* Event::mutable_userid() {
  set_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    userid_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Event.userId)
  return userid_;
}
inline ::std::string* Event::release_userid() {
  clear_has_userid();
  if (userid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = userid_;
    userid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Event::set_allocated_userid(::std::string* userid) {
  if (userid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete userid_;
  }
  if (userid) {
    set_has_userid();
    userid_ = userid;
  } else {
    clear_has_userid();
    userid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Event.userId)
}

// optional string eventDescription = 3;
inline bool Event::has_eventdescription() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Event::set_has_eventdescription() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Event::clear_has_eventdescription() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Event::clear_eventdescription() {
  if (eventdescription_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    eventdescription_->clear();
  }
  clear_has_eventdescription();
}
inline const ::std::string& Event::eventdescription() const {
  // @@protoc_insertion_point(field_get:Event.eventDescription)
  return *eventdescription_;
}
inline void Event::set_eventdescription(const ::std::string& value) {
  set_has_eventdescription();
  if (eventdescription_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    eventdescription_ = new ::std::string;
  }
  eventdescription_->assign(value);
  // @@protoc_insertion_point(field_set:Event.eventDescription)
}
inline void Event::set_eventdescription(const char* value) {
  set_has_eventdescription();
  if (eventdescription_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    eventdescription_ = new ::std::string;
  }
  eventdescription_->assign(value);
  // @@protoc_insertion_point(field_set_char:Event.eventDescription)
}
inline void Event::set_eventdescription(const char* value, size_t size) {
  set_has_eventdescription();
  if (eventdescription_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    eventdescription_ = new ::std::string;
  }
  eventdescription_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Event.eventDescription)
}
inline ::std::string* Event::mutable_eventdescription() {
  set_has_eventdescription();
  if (eventdescription_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    eventdescription_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Event.eventDescription)
  return eventdescription_;
}
inline ::std::string* Event::release_eventdescription() {
  clear_has_eventdescription();
  if (eventdescription_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = eventdescription_;
    eventdescription_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Event::set_allocated_eventdescription(::std::string* eventdescription) {
  if (eventdescription_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete eventdescription_;
  }
  if (eventdescription) {
    set_has_eventdescription();
    eventdescription_ = eventdescription;
  } else {
    clear_has_eventdescription();
    eventdescription_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Event.eventDescription)
}

// -------------------------------------------------------------------

// Events

// repeated .Event events = 1;
inline int Events::events_size() const {
  return events_.size();
}
inline void Events::clear_events() {
  events_.Clear();
}
inline const ::Event& Events::events(int index) const {
  // @@protoc_insertion_point(field_get:Events.events)
  return events_.Get(index);
}
inline ::Event* Events::mutable_events(int index) {
  // @@protoc_insertion_point(field_mutable:Events.events)
  return events_.Mutable(index);
}
inline ::Event* Events::add_events() {
  // @@protoc_insertion_point(field_add:Events.events)
  return events_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Event >&
Events::events() const {
  // @@protoc_insertion_point(field_list:Events.events)
  return events_;
}
inline ::google::protobuf::RepeatedPtrField< ::Event >*
Events::mutable_events() {
  // @@protoc_insertion_point(field_mutable_list:Events.events)
  return &events_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_events_2eproto__INCLUDED