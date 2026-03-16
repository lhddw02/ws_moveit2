// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from yolov8_obb_msgs:msg/InferenceResult.idl
// generated code does not contain a copyright notice

#include "yolov8_obb_msgs/msg/detail/inference_result__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_yolov8_obb_msgs
const rosidl_type_hash_t *
yolov8_obb_msgs__msg__InferenceResult__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3c, 0x21, 0x87, 0x3c, 0x55, 0x6e, 0x92, 0x58,
      0xbc, 0xc2, 0x11, 0x95, 0xdb, 0xfc, 0x1f, 0x9f,
      0x90, 0x8d, 0x6e, 0xca, 0x45, 0xcd, 0xcc, 0xdd,
      0x7b, 0xbb, 0x5c, 0xd7, 0x0a, 0xfd, 0xe4, 0xde,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char yolov8_obb_msgs__msg__InferenceResult__TYPE_NAME[] = "yolov8_obb_msgs/msg/InferenceResult";

// Define type names, field names, and default values
static char yolov8_obb_msgs__msg__InferenceResult__FIELD_NAME__class_name[] = "class_name";
static char yolov8_obb_msgs__msg__InferenceResult__FIELD_NAME__coordinates[] = "coordinates";

static rosidl_runtime_c__type_description__Field yolov8_obb_msgs__msg__InferenceResult__FIELDS[] = {
  {
    {yolov8_obb_msgs__msg__InferenceResult__FIELD_NAME__class_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {yolov8_obb_msgs__msg__InferenceResult__FIELD_NAME__coordinates, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
yolov8_obb_msgs__msg__InferenceResult__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {yolov8_obb_msgs__msg__InferenceResult__TYPE_NAME, 35, 35},
      {yolov8_obb_msgs__msg__InferenceResult__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string class_name\n"
  "float64[] coordinates";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
yolov8_obb_msgs__msg__InferenceResult__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {yolov8_obb_msgs__msg__InferenceResult__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 40, 40},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
yolov8_obb_msgs__msg__InferenceResult__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *yolov8_obb_msgs__msg__InferenceResult__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
