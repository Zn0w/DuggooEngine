#pragma once

#include <stdio.h>
#include <vector>


namespace dg { namespace graphics {

	enum ShaderDataType
	{
		NONE = 0,
		FLOAT,	FLOAT2,	FLOAT3,	FLOAT4,
		INT,	INT2,	INT3,	INT4,
		MAT3,	MAT4,
		BOOL
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case FLOAT	:	return 4;
		case FLOAT2	:	return 4 * 2;
		case FLOAT3	:	return 4 * 3;
		case FLOAT4	:	return 4 * 4;

		case INT	:	return 4;
		case INT2	:	return 4 * 2;
		case INT3	:	return 4 * 3;
		case INT4	:	return 4 * 4;

		case MAT3	:	return 4 * 3 * 3;
		case MAT4	:	return 4 * 4 * 4;

		case BOOL	:	return 1;


		default:
			printf("Unknown shader data type\n");
			return 0;
		}
	}
	
	struct BufferElement
	{
		ShaderDataType type;
		const char* name;
		unsigned int size;
		unsigned int offset;

		BufferElement(ShaderDataType s_type, const char* s_name)
			: type(s_type), name(s_name), size(ShaderDataTypeSize(type)), offset(0)
		{}

		unsigned int getComponentCount()
		{
			switch (type)
			{
			case FLOAT	:	return 1;
			case FLOAT2	:	return 2;
			case FLOAT3	:	return 3;
			case FLOAT4	:	return 4;

			case INT	:	return 1;
			case INT2	:	return 2;
			case INT3	:	return 3;
			case INT4	:	return 4;

			case MAT3	:	return 3 * 3;
			case MAT4	:	return 4 * 4;

			case BOOL	:	return 1;
			}
		}
	};
	
	class BufferLayout
	{
	public:
	private:
		std::vector<BufferElement> elements;
		unsigned int stride = 0;

	public:
		BufferLayout(const std::initializer_list<BufferElement>& s_elements)
			: elements(s_elements)
		{
			calculateOffsetAndStride();
		}
		
		inline const std::vector<BufferElement>& getElements() { return elements; }

	private:
		void calculateOffsetAndStride()
		{
			unsigned int offset = 0;
			stride = 0;

			for (BufferElement& element : elements)
			{
				element.offset = offset;
				offset += element.size;
				stride += element.size;
			}
		}
	};

} }