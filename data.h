// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file data.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _DATA_H_
#define _DATA_H_

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec(dllexport)
#else
#define eProsima_user_DllExport
#endif // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(data_SOURCE)
#define data_DllAPI __declspec(dllexport)
#else
#define data_DllAPI __declspec(dllimport)
#endif // data_SOURCE
#else
#define data_DllAPI
#endif // EPROSIMA_USER_DLL_EXPORT
#else
#define data_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    } // namespace fastcdr
} // namespace eprosima

/*!
 * @brief This class represents the structure can_frame_from_dds defined by the user in the IDL file.
 * @ingroup DATA
 */
class can_frame_from_dds
{
public:
    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport can_frame_from_dds();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~can_frame_from_dds();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object can_frame_from_dds that will be copied.
     */
    eProsima_user_DllExport can_frame_from_dds(
        const can_frame_from_dds &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object can_frame_from_dds that will be copied.
     */
    eProsima_user_DllExport can_frame_from_dds(
        can_frame_from_dds &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object can_frame_from_dds that will be copied.
     */
    eProsima_user_DllExport can_frame_from_dds &operator=(
        const can_frame_from_dds &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object can_frame_from_dds that will be copied.
     */
    eProsima_user_DllExport can_frame_from_dds &operator=(
        can_frame_from_dds &&x);

    /*!
     * @brief Comparison operator.
     * @param x can_frame_from_dds object to compare.
     */
    eProsima_user_DllExport bool operator==(
        const can_frame_from_dds &x);

    /*!
     * @brief Comparison operator.
     * @param x can_frame_from_dds object to compare.
     */
    eProsima_user_DllExport bool operator!=(
        const can_frame_from_dds &x);

    /*!
     * @brief This function sets a value in member ifn
     * @param _ifn New value for member ifn
     */
    eProsima_user_DllExport void ifn(
        uint8_t _ifn);

    /*!
     * @brief This function returns the value of member ifn
     * @return Value of member ifn
     */
    eProsima_user_DllExport uint8_t ifn() const;

    /*!
     * @brief This function returns a reference to member ifn
     * @return Reference to member ifn
     */
    eProsima_user_DllExport uint8_t &ifn();

    /*!
     * @brief This function sets a value in member id
     * @param _id New value for member id
     */
    eProsima_user_DllExport void id(
        uint32_t _id);

    /*!
     * @brief This function returns the value of member id
     * @return Value of member id
     */
    eProsima_user_DllExport uint32_t id() const;

    /*!
     * @brief This function returns a reference to member id
     * @return Reference to member id
     */
    eProsima_user_DllExport uint32_t &id();

    /*!
     * @brief This function sets a value in member idType
     * @param _idType New value for member idType
     */
    eProsima_user_DllExport void idType(
        uint8_t _idType);

    /*!
     * @brief This function returns the value of member idType
     * @return Value of member idType
     */
    eProsima_user_DllExport uint8_t idType() const;

    /*!
     * @brief This function returns a reference to member idType
     * @return Reference to member idType
     */
    eProsima_user_DllExport uint8_t &idType();

    /*!
     * @brief This function sets a value in member dataSize
     * @param _dataSize New value for member dataSize
     */
    eProsima_user_DllExport void dataSize(
        uint8_t _dataSize);

    /*!
     * @brief This function returns the value of member dataSize
     * @return Value of member dataSize
     */
    eProsima_user_DllExport uint8_t dataSize() const;

    /*!
     * @brief This function returns a reference to member dataSize
     * @return Reference to member dataSize
     */
    eProsima_user_DllExport uint8_t &dataSize();

    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
        const std::array<uint8_t, 8> &_data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
        std::array<uint8_t, 8> &&_data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::array<uint8_t, 8> &data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::array<uint8_t, 8> &data();
    /*!
     * @brief This function sets a value in member timeStamp
     * @param _timeStamp New value for member timeStamp
     */
    eProsima_user_DllExport void timeStamp(
        uint64_t _timeStamp);

    /*!
     * @brief This function returns the value of member timeStamp
     * @return Value of member timeStamp
     */
    eProsima_user_DllExport uint64_t timeStamp() const;

    /*!
     * @brief This function returns a reference to member timeStamp
     * @return Reference to member timeStamp
     */
    eProsima_user_DllExport uint64_t &timeStamp();

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
        size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
        const can_frame_from_dds &data,
        size_t current_alignment = 0);

    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr &cdr);

    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
        size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
        eprosima::fastcdr::Cdr &cdr) const;

private:
    uint8_t m_ifn;
    uint32_t m_id;
    uint8_t m_idType;
    uint8_t m_dataSize;
    std::array<uint8_t, 8> m_data;
    uint64_t m_timeStamp;
};
/*!
 * @brief This class represents the structure can_frame_from_bus defined by the user in the IDL file.
 * @ingroup DATA
 */
class can_frame_from_bus
{
public:
    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport can_frame_from_bus();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~can_frame_from_bus();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object can_frame_from_bus that will be copied.
     */
    eProsima_user_DllExport can_frame_from_bus(
        const can_frame_from_bus &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object can_frame_from_bus that will be copied.
     */
    eProsima_user_DllExport can_frame_from_bus(
        can_frame_from_bus &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object can_frame_from_bus that will be copied.
     */
    eProsima_user_DllExport can_frame_from_bus &operator=(
        const can_frame_from_bus &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object can_frame_from_bus that will be copied.
     */
    eProsima_user_DllExport can_frame_from_bus &operator=(
        can_frame_from_bus &&x);

    /*!
     * @brief Comparison operator.
     * @param x can_frame_from_bus object to compare.
     */
    eProsima_user_DllExport bool operator==(
        const can_frame_from_bus &x);

    /*!
     * @brief Comparison operator.
     * @param x can_frame_from_bus object to compare.
     */
    eProsima_user_DllExport bool operator!=(
        const can_frame_from_bus &x);

    /*!
     * @brief This function sets a value in member ifn
     * @param _ifn New value for member ifn
     */
    eProsima_user_DllExport void ifn(
        uint8_t _ifn);

    /*!
     * @brief This function returns the value of member ifn
     * @return Value of member ifn
     */
    eProsima_user_DllExport uint8_t ifn() const;

    /*!
     * @brief This function returns a reference to member ifn
     * @return Reference to member ifn
     */
    eProsima_user_DllExport uint8_t &ifn();

    /*!
     * @brief This function sets a value in member id
     * @param _id New value for member id
     */
    eProsima_user_DllExport void id(
        uint32_t _id);

    /*!
     * @brief This function returns the value of member id
     * @return Value of member id
     */
    eProsima_user_DllExport uint32_t id() const;

    /*!
     * @brief This function returns a reference to member id
     * @return Reference to member id
     */
    eProsima_user_DllExport uint32_t &id();

    /*!
     * @brief This function sets a value in member idType
     * @param _idType New value for member idType
     */
    eProsima_user_DllExport void idType(
        uint8_t _idType);

    /*!
     * @brief This function returns the value of member idType
     * @return Value of member idType
     */
    eProsima_user_DllExport uint8_t idType() const;

    /*!
     * @brief This function returns a reference to member idType
     * @return Reference to member idType
     */
    eProsima_user_DllExport uint8_t &idType();

    /*!
     * @brief This function sets a value in member dataSize
     * @param _dataSize New value for member dataSize
     */
    eProsima_user_DllExport void dataSize(
        uint8_t _dataSize);

    /*!
     * @brief This function returns the value of member dataSize
     * @return Value of member dataSize
     */
    eProsima_user_DllExport uint8_t dataSize() const;

    /*!
     * @brief This function returns a reference to member dataSize
     * @return Reference to member dataSize
     */
    eProsima_user_DllExport uint8_t &dataSize();

    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
        const std::array<uint8_t, 8> &_data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
        std::array<uint8_t, 8> &&_data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::array<uint8_t, 8> &data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::array<uint8_t, 8> &data();
    /*!
     * @brief This function sets a value in member timeStamp
     * @param _timeStamp New value for member timeStamp
     */
    eProsima_user_DllExport void timeStamp(
        uint64_t _timeStamp);

    /*!
     * @brief This function returns the value of member timeStamp
     * @return Value of member timeStamp
     */
    eProsima_user_DllExport uint64_t timeStamp() const;

    /*!
     * @brief This function returns a reference to member timeStamp
     * @return Reference to member timeStamp
     */
    eProsima_user_DllExport uint64_t &timeStamp();

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
        size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
        const can_frame_from_bus &data,
        size_t current_alignment = 0);

    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr &cdr);

    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
        size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
        eprosima::fastcdr::Cdr &cdr) const;

private:
    uint8_t m_ifn;
    uint32_t m_id;
    uint8_t m_idType;
    uint8_t m_dataSize;
    std::array<uint8_t, 8> m_data;
    uint64_t m_timeStamp;
};
/*!
 * @brief This class represents the structure modification defined by the user in the IDL file.
 * @ingroup DATA
 */
class modification
{
public:
    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport modification();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~modification();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object modification that will be copied.
     */
    eProsima_user_DllExport modification(
        const modification &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object modification that will be copied.
     */
    eProsima_user_DllExport modification(
        modification &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object modification that will be copied.
     */
    eProsima_user_DllExport modification &operator=(
        const modification &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object modification that will be copied.
     */
    eProsima_user_DllExport modification &operator=(
        modification &&x);

    /*!
     * @brief Comparison operator.
     * @param x modification object to compare.
     */
    eProsima_user_DllExport bool operator==(
        const modification &x);

    /*!
     * @brief Comparison operator.
     * @param x modification object to compare.
     */
    eProsima_user_DllExport bool operator!=(
        const modification &x);

    /*!
     * @brief This function sets a value in member id
     * @param _id New value for member id
     */
    eProsima_user_DllExport void id(
        uint32_t _id);

    /*!
     * @brief This function returns the value of member id
     * @return Value of member id
     */
    eProsima_user_DllExport uint32_t id() const;

    /*!
     * @brief This function returns a reference to member id
     * @return Reference to member id
     */
    eProsima_user_DllExport uint32_t &id();

    /*!
     * @brief This function sets a value in member idType
     * @param _idType New value for member idType
     */
    eProsima_user_DllExport void idType(
        uint8_t _idType);

    /*!
     * @brief This function returns the value of member idType
     * @return Value of member idType
     */
    eProsima_user_DllExport uint8_t idType() const;

    /*!
     * @brief This function returns a reference to member idType
     * @return Reference to member idType
     */
    eProsima_user_DllExport uint8_t &idType();

    /*!
     * @brief This function sets a value in member dataSize
     * @param _dataSize New value for member dataSize
     */
    eProsima_user_DllExport void dataSize(
        uint8_t _dataSize);

    /*!
     * @brief This function returns the value of member dataSize
     * @return Value of member dataSize
     */
    eProsima_user_DllExport uint8_t dataSize() const;

    /*!
     * @brief This function returns a reference to member dataSize
     * @return Reference to member dataSize
     */
    eProsima_user_DllExport uint8_t &dataSize();

    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
        const std::array<uint8_t, 8> &_data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
        std::array<uint8_t, 8> &&_data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::array<uint8_t, 8> &data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::array<uint8_t, 8> &data();

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
        size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
        const modification &data,
        size_t current_alignment = 0);

    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr &cdr);

    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
        size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
        eprosima::fastcdr::Cdr &cdr) const;

private:
    uint32_t m_id;
    uint8_t m_idType;
    uint8_t m_dataSize;
    std::array<uint8_t, 8> m_data;
};
/*!
 * @brief This class represents the bitmask config defined by the user in the IDL file.
 * @ingroup DATA
 */
enum config : uint8_t
{
    flag0 = 0x01 << 0,
    flag1 = 0x01 << 1,
    flag2 = 0x01 << 2,
    flag3 = 0x01 << 3,
    flag4 = 0x01 << 4,
    flag5 = 0x01 << 5,
    flag6 = 0x01 << 6,
    flag7 = 0x01 << 7
};

#endif // _DATA_H_