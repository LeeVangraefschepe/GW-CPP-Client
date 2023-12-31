#pragma once
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4996)
#pragma warning(disable : 5054)
#pragma warning(disable : 4244)
#pragma warning(disable : 4125)
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BlockUpdate.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_BlockUpdate_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_BlockUpdate_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_BlockUpdate_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_BlockUpdate_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_BlockUpdate_2eproto;
namespace packet {
class BlockUpdate;
class BlockUpdateDefaultTypeInternal;
extern BlockUpdateDefaultTypeInternal _BlockUpdate_default_instance_;
class BlockUpdate_Vector3;
class BlockUpdate_Vector3DefaultTypeInternal;
extern BlockUpdate_Vector3DefaultTypeInternal _BlockUpdate_Vector3_default_instance_;
}  // namespace packet
PROTOBUF_NAMESPACE_OPEN
template<> ::packet::BlockUpdate* Arena::CreateMaybeMessage<::packet::BlockUpdate>(Arena*);
template<> ::packet::BlockUpdate_Vector3* Arena::CreateMaybeMessage<::packet::BlockUpdate_Vector3>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace packet {

// ===================================================================

class BlockUpdate_Vector3 PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:packet.BlockUpdate.Vector3) */ {
 public:
  inline BlockUpdate_Vector3() : BlockUpdate_Vector3(nullptr) {}
  virtual ~BlockUpdate_Vector3();

  BlockUpdate_Vector3(const BlockUpdate_Vector3& from);
  BlockUpdate_Vector3(BlockUpdate_Vector3&& from) noexcept
    : BlockUpdate_Vector3() {
    *this = ::std::move(from);
  }

  inline BlockUpdate_Vector3& operator=(const BlockUpdate_Vector3& from) {
    CopyFrom(from);
    return *this;
  }
  inline BlockUpdate_Vector3& operator=(BlockUpdate_Vector3&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const BlockUpdate_Vector3& default_instance();

  static inline const BlockUpdate_Vector3* internal_default_instance() {
    return reinterpret_cast<const BlockUpdate_Vector3*>(
               &_BlockUpdate_Vector3_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(BlockUpdate_Vector3& a, BlockUpdate_Vector3& b) {
    a.Swap(&b);
  }
  inline void Swap(BlockUpdate_Vector3* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BlockUpdate_Vector3* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BlockUpdate_Vector3* New() const final {
    return CreateMaybeMessage<BlockUpdate_Vector3>(nullptr);
  }

  BlockUpdate_Vector3* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BlockUpdate_Vector3>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BlockUpdate_Vector3& from);
  void MergeFrom(const BlockUpdate_Vector3& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BlockUpdate_Vector3* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "packet.BlockUpdate.Vector3";
  }
  protected:
  explicit BlockUpdate_Vector3(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_BlockUpdate_2eproto);
    return ::descriptor_table_BlockUpdate_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
  };
  // int32 x = 1;
  void clear_x();
  ::PROTOBUF_NAMESPACE_ID::int32 x() const;
  void set_x(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_x() const;
  void _internal_set_x(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 y = 2;
  void clear_y();
  ::PROTOBUF_NAMESPACE_ID::int32 y() const;
  void set_y(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_y() const;
  void _internal_set_y(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 z = 3;
  void clear_z();
  ::PROTOBUF_NAMESPACE_ID::int32 z() const;
  void set_z(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_z() const;
  void _internal_set_z(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:packet.BlockUpdate.Vector3)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 x_;
  ::PROTOBUF_NAMESPACE_ID::int32 y_;
  ::PROTOBUF_NAMESPACE_ID::int32 z_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_BlockUpdate_2eproto;
};
// -------------------------------------------------------------------

class BlockUpdate PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:packet.BlockUpdate) */ {
 public:
  inline BlockUpdate() : BlockUpdate(nullptr) {}
  virtual ~BlockUpdate();

  BlockUpdate(const BlockUpdate& from);
  BlockUpdate(BlockUpdate&& from) noexcept
    : BlockUpdate() {
    *this = ::std::move(from);
  }

  inline BlockUpdate& operator=(const BlockUpdate& from) {
    CopyFrom(from);
    return *this;
  }
  inline BlockUpdate& operator=(BlockUpdate&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const BlockUpdate& default_instance();

  static inline const BlockUpdate* internal_default_instance() {
    return reinterpret_cast<const BlockUpdate*>(
               &_BlockUpdate_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(BlockUpdate& a, BlockUpdate& b) {
    a.Swap(&b);
  }
  inline void Swap(BlockUpdate* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BlockUpdate* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline BlockUpdate* New() const final {
    return CreateMaybeMessage<BlockUpdate>(nullptr);
  }

  BlockUpdate* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<BlockUpdate>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const BlockUpdate& from);
  void MergeFrom(const BlockUpdate& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BlockUpdate* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "packet.BlockUpdate";
  }
  protected:
  explicit BlockUpdate(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_BlockUpdate_2eproto);
    return ::descriptor_table_BlockUpdate_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef BlockUpdate_Vector3 Vector3;

  // accessors -------------------------------------------------------

  enum : int {
    kPositionFieldNumber = 2,
    kPacketIdFieldNumber = 1,
    kBlockFieldNumber = 3,
    kBlockDataFieldNumber = 4,
  };
  // .packet.BlockUpdate.Vector3 position = 2;
  bool has_position() const;
  private:
  bool _internal_has_position() const;
  public:
  void clear_position();
  const ::packet::BlockUpdate_Vector3& position() const;
  ::packet::BlockUpdate_Vector3* release_position();
  ::packet::BlockUpdate_Vector3* mutable_position();
  void set_allocated_position(::packet::BlockUpdate_Vector3* position);
  private:
  const ::packet::BlockUpdate_Vector3& _internal_position() const;
  ::packet::BlockUpdate_Vector3* _internal_mutable_position();
  public:
  void unsafe_arena_set_allocated_position(
      ::packet::BlockUpdate_Vector3* position);
  ::packet::BlockUpdate_Vector3* unsafe_arena_release_position();

  // int32 packetId = 1;
  void clear_packetid();
  ::PROTOBUF_NAMESPACE_ID::int32 packetid() const;
  void set_packetid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_packetid() const;
  void _internal_set_packetid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 block = 3;
  void clear_block();
  ::PROTOBUF_NAMESPACE_ID::int32 block() const;
  void set_block(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_block() const;
  void _internal_set_block(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 blockData = 4;
  void clear_blockdata();
  ::PROTOBUF_NAMESPACE_ID::int32 blockdata() const;
  void set_blockdata(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_blockdata() const;
  void _internal_set_blockdata(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:packet.BlockUpdate)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::packet::BlockUpdate_Vector3* position_;
  ::PROTOBUF_NAMESPACE_ID::int32 packetid_;
  ::PROTOBUF_NAMESPACE_ID::int32 block_;
  ::PROTOBUF_NAMESPACE_ID::int32 blockdata_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_BlockUpdate_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BlockUpdate_Vector3

// int32 x = 1;
inline void BlockUpdate_Vector3::clear_x() {
  x_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate_Vector3::_internal_x() const {
  return x_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate_Vector3::x() const {
  // @@protoc_insertion_point(field_get:packet.BlockUpdate.Vector3.x)
  return _internal_x();
}
inline void BlockUpdate_Vector3::_internal_set_x(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  x_ = value;
}
inline void BlockUpdate_Vector3::set_x(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:packet.BlockUpdate.Vector3.x)
}

// int32 y = 2;
inline void BlockUpdate_Vector3::clear_y() {
  y_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate_Vector3::_internal_y() const {
  return y_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate_Vector3::y() const {
  // @@protoc_insertion_point(field_get:packet.BlockUpdate.Vector3.y)
  return _internal_y();
}
inline void BlockUpdate_Vector3::_internal_set_y(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  y_ = value;
}
inline void BlockUpdate_Vector3::set_y(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:packet.BlockUpdate.Vector3.y)
}

// int32 z = 3;
inline void BlockUpdate_Vector3::clear_z() {
  z_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate_Vector3::_internal_z() const {
  return z_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate_Vector3::z() const {
  // @@protoc_insertion_point(field_get:packet.BlockUpdate.Vector3.z)
  return _internal_z();
}
inline void BlockUpdate_Vector3::_internal_set_z(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  z_ = value;
}
inline void BlockUpdate_Vector3::set_z(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:packet.BlockUpdate.Vector3.z)
}

// -------------------------------------------------------------------

// BlockUpdate

// int32 packetId = 1;
inline void BlockUpdate::clear_packetid() {
  packetid_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate::_internal_packetid() const {
  return packetid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate::packetid() const {
  // @@protoc_insertion_point(field_get:packet.BlockUpdate.packetId)
  return _internal_packetid();
}
inline void BlockUpdate::_internal_set_packetid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  packetid_ = value;
}
inline void BlockUpdate::set_packetid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_packetid(value);
  // @@protoc_insertion_point(field_set:packet.BlockUpdate.packetId)
}

// .packet.BlockUpdate.Vector3 position = 2;
inline bool BlockUpdate::_internal_has_position() const {
  return this != internal_default_instance() && position_ != nullptr;
}
inline bool BlockUpdate::has_position() const {
  return _internal_has_position();
}
inline void BlockUpdate::clear_position() {
  if (GetArena() == nullptr && position_ != nullptr) {
    delete position_;
  }
  position_ = nullptr;
}
inline const ::packet::BlockUpdate_Vector3& BlockUpdate::_internal_position() const {
  const ::packet::BlockUpdate_Vector3* p = position_;
  return p != nullptr ? *p : reinterpret_cast<const ::packet::BlockUpdate_Vector3&>(
      ::packet::_BlockUpdate_Vector3_default_instance_);
}
inline const ::packet::BlockUpdate_Vector3& BlockUpdate::position() const {
  // @@protoc_insertion_point(field_get:packet.BlockUpdate.position)
  return _internal_position();
}
inline void BlockUpdate::unsafe_arena_set_allocated_position(
    ::packet::BlockUpdate_Vector3* position) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(position_);
  }
  position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:packet.BlockUpdate.position)
}
inline ::packet::BlockUpdate_Vector3* BlockUpdate::release_position() {
  
  ::packet::BlockUpdate_Vector3* temp = position_;
  position_ = nullptr;
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::packet::BlockUpdate_Vector3* BlockUpdate::unsafe_arena_release_position() {
  // @@protoc_insertion_point(field_release:packet.BlockUpdate.position)
  
  ::packet::BlockUpdate_Vector3* temp = position_;
  position_ = nullptr;
  return temp;
}
inline ::packet::BlockUpdate_Vector3* BlockUpdate::_internal_mutable_position() {
  
  if (position_ == nullptr) {
    auto* p = CreateMaybeMessage<::packet::BlockUpdate_Vector3>(GetArena());
    position_ = p;
  }
  return position_;
}
inline ::packet::BlockUpdate_Vector3* BlockUpdate::mutable_position() {
  // @@protoc_insertion_point(field_mutable:packet.BlockUpdate.position)
  return _internal_mutable_position();
}
inline void BlockUpdate::set_allocated_position(::packet::BlockUpdate_Vector3* position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete position_;
  }
  if (position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(position);
    if (message_arena != submessage_arena) {
      position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:packet.BlockUpdate.position)
}

// int32 block = 3;
inline void BlockUpdate::clear_block() {
  block_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate::_internal_block() const {
  return block_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate::block() const {
  // @@protoc_insertion_point(field_get:packet.BlockUpdate.block)
  return _internal_block();
}
inline void BlockUpdate::_internal_set_block(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  block_ = value;
}
inline void BlockUpdate::set_block(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_block(value);
  // @@protoc_insertion_point(field_set:packet.BlockUpdate.block)
}

// int32 blockData = 4;
inline void BlockUpdate::clear_blockdata() {
  blockdata_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate::_internal_blockdata() const {
  return blockdata_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 BlockUpdate::blockdata() const {
  // @@protoc_insertion_point(field_get:packet.BlockUpdate.blockData)
  return _internal_blockdata();
}
inline void BlockUpdate::_internal_set_blockdata(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  blockdata_ = value;
}
inline void BlockUpdate::set_blockdata(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_blockdata(value);
  // @@protoc_insertion_point(field_set:packet.BlockUpdate.blockData)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace packet

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_BlockUpdate_2eproto
#pragma warning(pop)