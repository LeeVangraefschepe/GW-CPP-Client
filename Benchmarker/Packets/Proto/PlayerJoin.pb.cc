#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4996)
#pragma warning(disable : 5054)
#pragma warning(disable : 4244)
#pragma warning(disable : 4125)
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PlayerJoin.proto

#include "PlayerJoin.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_PlayerJoin_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PlayerJoin_Vector3f_PlayerJoin_2eproto;
namespace packet {
class PlayerJoin_Vector3fDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PlayerJoin_Vector3f> _instance;
} _PlayerJoin_Vector3f_default_instance_;
class PlayerJoinDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PlayerJoin> _instance;
} _PlayerJoin_default_instance_;
}  // namespace packet
static void InitDefaultsscc_info_PlayerJoin_PlayerJoin_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::packet::_PlayerJoin_default_instance_;
    new (ptr) ::packet::PlayerJoin();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_PlayerJoin_PlayerJoin_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_PlayerJoin_PlayerJoin_2eproto}, {
      &scc_info_PlayerJoin_Vector3f_PlayerJoin_2eproto.base,}};

static void InitDefaultsscc_info_PlayerJoin_Vector3f_PlayerJoin_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::packet::_PlayerJoin_Vector3f_default_instance_;
    new (ptr) ::packet::PlayerJoin_Vector3f();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PlayerJoin_Vector3f_PlayerJoin_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_PlayerJoin_Vector3f_PlayerJoin_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_PlayerJoin_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_PlayerJoin_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_PlayerJoin_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_PlayerJoin_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin_Vector3f, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin_Vector3f, x_),
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin_Vector3f, y_),
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin_Vector3f, z_),
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin, packetid_),
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin, playerid_),
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin, message_),
  PROTOBUF_FIELD_OFFSET(::packet::PlayerJoin, position_),
  1,
  2,
  0,
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::packet::PlayerJoin_Vector3f)},
  { 8, 17, sizeof(::packet::PlayerJoin)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::packet::_PlayerJoin_Vector3f_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::packet::_PlayerJoin_default_instance_),
};

const char descriptor_table_protodef_PlayerJoin_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020PlayerJoin.proto\022\006packet\"\322\001\n\nPlayerJoi"
  "n\022\025\n\010packetId\030\001 \001(\005H\000\210\001\001\022\025\n\010playerId\030\002 \001"
  "(\005H\001\210\001\001\022\024\n\007message\030\003 \001(\tH\002\210\001\001\022-\n\010positio"
  "n\030\004 \001(\0132\033.packet.PlayerJoin.Vector3f\032+\n\010"
  "Vector3f\022\t\n\001x\030\001 \001(\002\022\t\n\001y\030\002 \001(\002\022\t\n\001z\030\003 \001("
  "\002B\013\n\t_packetIdB\013\n\t_playerIdB\n\n\010_messageb"
  "\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_PlayerJoin_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_PlayerJoin_2eproto_sccs[2] = {
  &scc_info_PlayerJoin_PlayerJoin_2eproto.base,
  &scc_info_PlayerJoin_Vector3f_PlayerJoin_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_PlayerJoin_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_PlayerJoin_2eproto = {
  false, false, descriptor_table_protodef_PlayerJoin_2eproto, "PlayerJoin.proto", 247,
  &descriptor_table_PlayerJoin_2eproto_once, descriptor_table_PlayerJoin_2eproto_sccs, descriptor_table_PlayerJoin_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_PlayerJoin_2eproto::offsets,
  file_level_metadata_PlayerJoin_2eproto, 2, file_level_enum_descriptors_PlayerJoin_2eproto, file_level_service_descriptors_PlayerJoin_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_PlayerJoin_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_PlayerJoin_2eproto)), true);
namespace packet {

// ===================================================================

class PlayerJoin_Vector3f::_Internal {
 public:
};

PlayerJoin_Vector3f::PlayerJoin_Vector3f(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:packet.PlayerJoin.Vector3f)
}
PlayerJoin_Vector3f::PlayerJoin_Vector3f(const PlayerJoin_Vector3f& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&z_) -
    reinterpret_cast<char*>(&x_)) + sizeof(z_));
  // @@protoc_insertion_point(copy_constructor:packet.PlayerJoin.Vector3f)
}

void PlayerJoin_Vector3f::SharedCtor() {
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&x_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&z_) -
      reinterpret_cast<char*>(&x_)) + sizeof(z_));
}

PlayerJoin_Vector3f::~PlayerJoin_Vector3f() {
  // @@protoc_insertion_point(destructor:packet.PlayerJoin.Vector3f)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PlayerJoin_Vector3f::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void PlayerJoin_Vector3f::ArenaDtor(void* object) {
  PlayerJoin_Vector3f* _this = reinterpret_cast< PlayerJoin_Vector3f* >(object);
  (void)_this;
}
void PlayerJoin_Vector3f::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PlayerJoin_Vector3f::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PlayerJoin_Vector3f& PlayerJoin_Vector3f::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PlayerJoin_Vector3f_PlayerJoin_2eproto.base);
  return *internal_default_instance();
}


void PlayerJoin_Vector3f::Clear() {
// @@protoc_insertion_point(message_clear_start:packet.PlayerJoin.Vector3f)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&z_) -
      reinterpret_cast<char*>(&x_)) + sizeof(z_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PlayerJoin_Vector3f::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // float x = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 13)) {
          x_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float y = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 21)) {
          y_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // float z = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          z_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PlayerJoin_Vector3f::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:packet.PlayerJoin.Vector3f)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // float x = 1;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(1, this->_internal_x(), target);
  }

  // float y = 2;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(2, this->_internal_y(), target);
  }

  // float z = 3;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_z(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:packet.PlayerJoin.Vector3f)
  return target;
}

size_t PlayerJoin_Vector3f::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:packet.PlayerJoin.Vector3f)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // float x = 1;
  if (!(this->x() <= 0 && this->x() >= 0)) {
    total_size += 1 + 4;
  }

  // float y = 2;
  if (!(this->y() <= 0 && this->y() >= 0)) {
    total_size += 1 + 4;
  }

  // float z = 3;
  if (!(this->z() <= 0 && this->z() >= 0)) {
    total_size += 1 + 4;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PlayerJoin_Vector3f::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:packet.PlayerJoin.Vector3f)
  GOOGLE_DCHECK_NE(&from, this);
  const PlayerJoin_Vector3f* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PlayerJoin_Vector3f>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:packet.PlayerJoin.Vector3f)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:packet.PlayerJoin.Vector3f)
    MergeFrom(*source);
  }
}

void PlayerJoin_Vector3f::MergeFrom(const PlayerJoin_Vector3f& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:packet.PlayerJoin.Vector3f)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!(from.x() <= 0 && from.x() >= 0)) {
    _internal_set_x(from._internal_x());
  }
  if (!(from.y() <= 0 && from.y() >= 0)) {
    _internal_set_y(from._internal_y());
  }
  if (!(from.z() <= 0 && from.z() >= 0)) {
    _internal_set_z(from._internal_z());
  }
}

void PlayerJoin_Vector3f::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:packet.PlayerJoin.Vector3f)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerJoin_Vector3f::CopyFrom(const PlayerJoin_Vector3f& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:packet.PlayerJoin.Vector3f)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerJoin_Vector3f::IsInitialized() const {
  return true;
}

void PlayerJoin_Vector3f::InternalSwap(PlayerJoin_Vector3f* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PlayerJoin_Vector3f, z_)
      + sizeof(PlayerJoin_Vector3f::z_)
      - PROTOBUF_FIELD_OFFSET(PlayerJoin_Vector3f, x_)>(
          reinterpret_cast<char*>(&x_),
          reinterpret_cast<char*>(&other->x_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PlayerJoin_Vector3f::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class PlayerJoin::_Internal {
 public:
  using HasBits = decltype(std::declval<PlayerJoin>()._has_bits_);
  static void set_has_packetid(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_playerid(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_message(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::packet::PlayerJoin_Vector3f& position(const PlayerJoin* msg);
};

const ::packet::PlayerJoin_Vector3f&
PlayerJoin::_Internal::position(const PlayerJoin* msg) {
  return *msg->position_;
}
PlayerJoin::PlayerJoin(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:packet.PlayerJoin)
}
PlayerJoin::PlayerJoin(const PlayerJoin& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_message()) {
    message_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_message(), 
      GetArena());
  }
  if (from._internal_has_position()) {
    position_ = new ::packet::PlayerJoin_Vector3f(*from.position_);
  } else {
    position_ = nullptr;
  }
  ::memcpy(&packetid_, &from.packetid_,
    static_cast<size_t>(reinterpret_cast<char*>(&playerid_) -
    reinterpret_cast<char*>(&packetid_)) + sizeof(playerid_));
  // @@protoc_insertion_point(copy_constructor:packet.PlayerJoin)
}

void PlayerJoin::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_PlayerJoin_PlayerJoin_2eproto.base);
  message_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&position_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&playerid_) -
      reinterpret_cast<char*>(&position_)) + sizeof(playerid_));
}

PlayerJoin::~PlayerJoin() {
  // @@protoc_insertion_point(destructor:packet.PlayerJoin)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PlayerJoin::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  message_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete position_;
}

void PlayerJoin::ArenaDtor(void* object) {
  PlayerJoin* _this = reinterpret_cast< PlayerJoin* >(object);
  (void)_this;
}
void PlayerJoin::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PlayerJoin::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PlayerJoin& PlayerJoin::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PlayerJoin_PlayerJoin_2eproto.base);
  return *internal_default_instance();
}


void PlayerJoin::Clear() {
// @@protoc_insertion_point(message_clear_start:packet.PlayerJoin)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    message_.ClearNonDefaultToEmpty();
  }
  if (GetArena() == nullptr && position_ != nullptr) {
    delete position_;
  }
  position_ = nullptr;
  if (cached_has_bits & 0x00000006u) {
    ::memset(&packetid_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&playerid_) -
        reinterpret_cast<char*>(&packetid_)) + sizeof(playerid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PlayerJoin::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 packetId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_packetid(&has_bits);
          packetid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 playerId = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_playerid(&has_bits);
          playerid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string message = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_message();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "packet.PlayerJoin.message"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .packet.PlayerJoin.Vector3f position = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_position(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PlayerJoin::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:packet.PlayerJoin)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 packetId = 1;
  if (_internal_has_packetid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_packetid(), target);
  }

  // int32 playerId = 2;
  if (_internal_has_playerid()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_playerid(), target);
  }

  // string message = 3;
  if (_internal_has_message()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message().data(), static_cast<int>(this->_internal_message().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "packet.PlayerJoin.message");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_message(), target);
  }

  // .packet.PlayerJoin.Vector3f position = 4;
  if (this->has_position()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        4, _Internal::position(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:packet.PlayerJoin)
  return target;
}

size_t PlayerJoin::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:packet.PlayerJoin)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string message = 3;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_message());
  }

  // .packet.PlayerJoin.Vector3f position = 4;
  if (this->has_position()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *position_);
  }

  if (cached_has_bits & 0x00000006u) {
    // int32 packetId = 1;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_packetid());
    }

    // int32 playerId = 2;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_playerid());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PlayerJoin::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:packet.PlayerJoin)
  GOOGLE_DCHECK_NE(&from, this);
  const PlayerJoin* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PlayerJoin>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:packet.PlayerJoin)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:packet.PlayerJoin)
    MergeFrom(*source);
  }
}

void PlayerJoin::MergeFrom(const PlayerJoin& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:packet.PlayerJoin)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_message()) {
    _internal_set_message(from._internal_message());
  }
  if (from.has_position()) {
    _internal_mutable_position()->::packet::PlayerJoin_Vector3f::MergeFrom(from._internal_position());
  }
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000006u) {
    if (cached_has_bits & 0x00000002u) {
      packetid_ = from.packetid_;
    }
    if (cached_has_bits & 0x00000004u) {
      playerid_ = from.playerid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void PlayerJoin::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:packet.PlayerJoin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PlayerJoin::CopyFrom(const PlayerJoin& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:packet.PlayerJoin)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PlayerJoin::IsInitialized() const {
  return true;
}

void PlayerJoin::InternalSwap(PlayerJoin* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  message_.Swap(&other->message_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PlayerJoin, playerid_)
      + sizeof(PlayerJoin::playerid_)
      - PROTOBUF_FIELD_OFFSET(PlayerJoin, position_)>(
          reinterpret_cast<char*>(&position_),
          reinterpret_cast<char*>(&other->position_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PlayerJoin::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace packet
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::packet::PlayerJoin_Vector3f* Arena::CreateMaybeMessage< ::packet::PlayerJoin_Vector3f >(Arena* arena) {
  return Arena::CreateMessageInternal< ::packet::PlayerJoin_Vector3f >(arena);
}
template<> PROTOBUF_NOINLINE ::packet::PlayerJoin* Arena::CreateMaybeMessage< ::packet::PlayerJoin >(Arena* arena) {
  return Arena::CreateMessageInternal< ::packet::PlayerJoin >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
#pragma warning(pop)