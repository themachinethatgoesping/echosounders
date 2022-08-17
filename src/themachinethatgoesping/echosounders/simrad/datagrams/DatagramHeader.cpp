// SPDX-FileCopyrightText: 2022 Tim Weiß, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, GEOMAR Helmholtz Centre for Ocean Research Kiel
// SPDX-FileCopyrightText: 2022 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "DatagramHeader.h"

namespace Ek60
{

	DatagramHeader::DatagramHeader()
	{
	}

    DatagramHeader::DatagramHeader(ek60_long type, DateTime time)
		: datagramType(type), dateTime(time)
	{
	}

	DatagramHeader::~DatagramHeader()
	{
	}

    ek60_long DatagramHeader::GetDatagramType()const
	{
		return datagramType;
	}
    DateTime DatagramHeader::GetDateTime()const
	{
		return dateTime;
	}

    void DatagramHeader::SetDatagramType(ek60_long type)
	{
		datagramType = type;
	}

    void DatagramHeader::SetDateTime(ek60_long low, ek60_long high)
	{
		dateTime.SetLowTime(low);
        dateTime.SetHighTime(high);
    }

    std::string DatagramHeader::GetDatagramType_asString() const
    {
        return DSMToolsLib::helperfunctions::convertEk80LongToString (datagramType);
    }

}
