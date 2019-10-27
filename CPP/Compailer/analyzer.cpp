#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include "analyzer.h"

string analyzer_t::s_predefinedTypesStrings[] =
    {"char", "short", "int", "long", "float", "double", "void"};
string analyzer_t::s_keyWordsStrings[] =
    {"if", "else", "for", "while", "class",
     "private", "public", "protected", "main", "const", "virtual"};
string analyzer_t::s_operatorsStrings[] =
    {"++", "--", "==", "->", "=", "+", "-", "*", "&", "<<", ">>"};
string analyzer_t::s_predefTokensStrings[] =
    {"(", ")", "[", "]", "{", "}", ";", "<", ">", "=", "+", "-", "*", "&"};

void analyzer_t::initialAnalyzer()
{
    m_programStarted = false;
    m_predefTypeEncountered = false;
    m_curlyBracCount = 0;
    m_minus = 0;
    m_squareBracCount = 0;
    m_roundBracCount = 0;
    m_pointBracCount = 0;
    m_plus = 0;
    m_if = false;
}
static void PrintEnclErr(const char &brace, const int &countbrace)
{
    if (countbrace > 0)
    {
        cout << "error - " << brace << " '" << countbrace << "' not closed" << endl;
    }
}
void analyzer_t::completeAnalyze()
{
    m_if = false;

    PrintEnclErr('<', m_pointBracCount);
    PrintEnclErr('{', m_curlyBracCount);
    PrintEnclErr('[', m_squareBracCount);
    PrintEnclErr('(', m_roundBracCount);
}
bool analyzer_t::isValidVarName(const string &_token) const
{
    return (isalpha(_token[0]) || _token[0] == '_');
}

void analyzer_t::analyzeLine(tokenizer_t &t, size_t lineNum)
{
    vector<string>::iterator m_nextToken;
    *(m_nextToken) = t.getVector().begin();

    while (m_nextToken != t.getVector().end())
    {
        analyzeToken(*(m_nextToken), lineNum);

        m_nextToken++;
    }
}

bool analyzer_t::CheckEnclosure(const string &_token, size_t _lineNum)
{
    return (EnclosureFuncCheck(_token, "{", "}", m_curlyBracCount, _lineNum) || EnclosureFuncCheck(_token, "(", ")", m_roundBracCount, _lineNum) || EnclosureFuncCheck(_token, "[", "]", m_squareBracCount, _lineNum));
}

static bool EnclosureFuncCheck(const string &_token, const string _open, const string _close, int &counter, size_t _lineNum)
{
    if (_open == _token || _token == _close)
    {
        if (m_predefTypeEncountered)
        {
            cout << "line " << _lineNum << ": error - illgel var name error\n"<< endl;
            m_predefTypeEncountered = false;
        }
        if (_token == _close)
        {
            if (counter > 0)
            {
                counter--;
                return true;
            }
            else
            {

                cout << "line " << _lineNum << ": error - " << _token << " without " << _close << "\n"
                     << endl;
                return true;
            }
            else if (_token == _open)
            {
                counter++;
                return true;
            }
        }
    }
    return false;
}
bool analyzer_t::checkOperators(const string &_token, size_t _lineNum)
{
    if (_token == "+")
    {
        if (m_plus < 2)
        {
            m_plus++;
            m_minus = 0;
            return true;
        }
        else
        {
            cout << "line " << _lineNum << ": error - no operator ";
            cout << _token << _token << _token << "\n"
                 << endl;
            this->m_plus = 0;
            return true;
        }
    }
    if (_token == "-")
    {
        if (m_minus < 2)
        {
            m_minus++;
            m_plus = 0;
            return true;
        }
        else
        {
            cout << "line " << _lineNum << ": error - no operator ";
            cout << _token << _token << _token << "\n"
                 << endl;
            this->m_minus = 0;
            return true;
        }
    }
    m_minus = 0;
    m_plus = 0;
    return false;
}

void analyzer_t::analyzeToken(const string &_token, size_t _lineNum)
{
    if (!m_programStarted)
    {
        if (_token != "main")
        {
            cout << "line " << _lineNum << ": error - the program doesn't start with 'main'\n"
                 << endl;
        }
        m_programStarted = true;
    }
    if (checkOperators(_token, _lineNum))
    {
        return;
    }
    if (CheckEnclosure(_token, _lineNum) || CheckEnclosureIFELSE(_token, _lineNum))
    {
        return;
    }
    if (s_predefinedTypesStrings.find(_token) != s_predefinedTypesStrings.end())
    {
        if (m_predefTypeEncountered)
        {
            cout << "line " << _lineNum << ": error - multiple type declaration\n"
                 << endl;
            m_predefTypeEncountered = false;
        }
        else
        {
            m_predefTypeEncountered = true;
        }
        return;
    }
    if (m_predefTypeEncountered)
    {
        if (s_keyWordsStrings.find(_token) != s_keyWordsStrings.end() ||
            s_operatorsStrings.find(_token) != s_operatorsStrings.end() ||
            s_predefTokensStrings.find(_token) != s_predefTokensStrings.end())
        {
            cout << "line " << _lineNum << ": error - illegal variable name\n"
                 << endl;
        }
        else
        {
            if (m_symbolTable.find(_token) != m_symbolTable.end())
            {
                cout << "line " << _lineNum << ": error - variable '" << _token << "' already declared\n"
                     << endl;
            }
            else
            {
                if (IsValidVarName(_token))
                {
                    m_symbolTable.insert(_token);
                }
                else
                {
                    cout << "line " << _lineNum << ": error - illegal variable name\n"
                         << endl;
                }
            }
        }
        m_predefTypeEncountered = false;
    }
    else
    {
        if (!(s_keyWordsStrings.find(_token) != s_keyWordsStrings.end() ||
              s_operatorsStrings.find(_token) != s_operatorsStrings.end() ||
              s_predefTokensStrings.find(_token) != s_predefTokensStrings.end()) &&
            IsValidVarName(_token) &&
            m_symbolTable.find(_token) == m_symbolTable.end())
        {
            cout << "line " << _lineNum << ": error - " << _token << " is not declared\n"
                 << endl;
        }
    }
}

static bool CheckEnclosureIFELSE(const string &_token, size_t _lineNum)
{
    if (_token == "else")
    {
        if (m_if == false)
        {
            cout << "line " << _lineNum << ": error - there is else without if\n"
                 << endl;
            return true;
        }
        return true;
    }
    if (_token == "if")
    {
        m_if = true;
        return true;
    }
    return false;
}