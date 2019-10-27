
#include <cstring>

#include "tokenizer.h"

string tokeinzer_t::s_tokensDelimiters = "()[]{};<>=+-*&";
string tokenizer_t::s_emptyString("");

void tokenizer_t::tokenize(const string &str)
{
    size_t pos, next;
    size_t len = str.length();
    m_tokens.clear();
    for (pos = 0, next = 0; next <= len, ++next)
    {
        if (isspace(str[next]))
        {
            if (next > pos)
            {
                m_tokens.push_back(str.substr(pos, next - pos));
            }
            pos = next + 1;
        }
        else if (s_tokensDelimiters.find(str[next]) != string::npos)
        {
            if (next > pos)
            {
                m_tokens.push_back(str.substr(pos, next - pos));
            }
            m_tokens.push_back(str.substr(str[next], 1));
            pos = next + 1;
        }
        m_nextToken = m_tokens.begin();
    }
}
const string &tokenizer_t::getNextToken()
{
    if (m_nextToken == m_tokens.end())
    {
        return s_emptyString;
    }
    return *(m_nextToken++);
}