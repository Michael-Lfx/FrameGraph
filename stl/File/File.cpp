// Copyright (c) 2018,  Zhirnov Andrey. For more information see 'LICENSE'

#include "stl/File/File.h"
#include "stl/Algorithms/StringUtils.h"


namespace FG
{
	
/*
=================================================
    Read
=================================================
*/
	bool  RFile::Read (void *buffer, BytesU size)
	{
		return Read2( buffer, size ) == size;
	}
	
/*
=================================================
    Read
=================================================
*/
	bool  RFile::Read (size_t length, OUT String &str)
	{
		str.resize( length );

		BytesU	expected_size	= BytesU::SizeOf(str[0]) * str.length();
		BytesU	current_size	= Read2( str.data(), expected_size );
		
		str.resize( size_t(current_size / sizeof(str[0])) );

		return str.length() == length;
	}
	
/*
=================================================
    Read
=================================================
*/
	bool  RFile::Read (size_t count, OUT Array<uint8_t> &buf)
	{
		buf.resize( count );

		BytesU	expected_size	= BytesU::SizeOf(buf[0]) * buf.size();
		BytesU	current_size	= Read2( buf.data(), expected_size );
		
		buf.resize( size_t(current_size / sizeof(buf[0])) );

		return buf.size() == count;
	}
//-----------------------------------------------------------------------------
	


/*
=================================================
    Write
=================================================
*/
	bool  WFile::Write (const void *buffer, BytesU size)
	{
		return Write2( buffer, size ) == size;
	}
	
/*
=================================================
    Write
=================================================
*/
	bool  WFile::Write (StringView str)
	{
		BytesU	size = BytesU::SizeOf(str[0]) * str.length();

		return Write2( str.data(), size ) == size;
	}
	
/*
=================================================
    Write
=================================================
*/
	bool  WFile::Write (ArrayView<uint8_t> buf)
	{
		BytesU	size = BytesU::SizeOf(buf[0]) * buf.size();

		return Write2( buf.data(), size ) == size;
	}

}	// FG