#include "memPage_t.h"
#include <string>

bool memPage_t::isMemEmpty()
{
	if (m_actualSize == 0)
		return true;
	else
		return false;
}
bool memPage_t::isMemFull()
{
	return m_actualSize == capacity ? true : false;
}
char *memPage_t::read(void *output, size_t bytes)
{
	if (output != 0)
	{
		if (m_currentPosition + bytes > m_actualSize)
		{
			memcpy(output, (void *)(&(buffer[m_currentPosition])), m_actualSize - m_currentPosition);
			m_currentPosition = m_actualSize;
		}
		else
		{
			memcpy(output, (void *)(&(buffer[m_currentPosition])), bytes);
			m_currentPosition += bytes;
		}
	}
	return (char *)output;
}
char *memPage_t::read(void *output, const size_t pos, size_t bytes)
{
	if (output != 0 && pos <= m_actualSize)
	{
		m_currentPosition = pos;
		if (m_currentPosition + bytes > m_actualSize)
		{
			memcpy(output, (void *)(&(buffer[m_currentPosition])), m_actualSize - m_currentPosition);
			m_currentPosition = m_actualSize;
		}
		else
		{
			memcpy(output, (void *)(&(buffer[m_currentPosition])), bytes);
			m_currentPosition += bytes;
		}
	}
	return (char *)output;
}
size_t memPage_t::write(const char *inputBuffer, size_t bufferSize)
{
	int numOfBytes;
	if (m_currentPosition + bufferSize > capacity)
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, capacity - m_currentPosition);
		numOfBytes = capacity - m_currentPosition;
		m_actualSize = capacity;
		m_currentPosition = capacity;
	}
	else
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, bufferSize);
		if (m_actualSize < m_currentPosition + bufferSize)
		{
			m_actualSize = m_currentPosition + bufferSize;
		}
		m_currentPosition += bufferSize;
		numOfBytes = bufferSize;
	}
	return numOfBytes;
}
size_t memPage_t::write(const char *inputBuffer, size_t bufferSize, size_t pos)
{
	if (pos > m_actualSize)
	{
		return 0;
	}
	int numOfBytes;
	m_currentPosition = pos;
	if (m_currentPosition + bufferSize > capacity)
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, capacity - m_currentPosition);
		numOfBytes = capacity - m_currentPosition;
		m_actualSize = capacity;
		m_currentPosition = capacity;
	}
	else
	{
		memcpy((void *)(&(buffer[m_currentPosition])), (void *)inputBuffer, bufferSize);
		if (m_actualSize < m_currentPosition + bufferSize)
		{
			m_actualSize = m_currentPosition + bufferSize;
		}
		m_currentPosition += bufferSize;
		numOfBytes = bufferSize;
	}
	return numOfBytes;
}