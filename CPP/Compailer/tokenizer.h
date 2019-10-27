#ifndef TOKENIZER_T_H
#define TOKENIZER_T_H
#include <string>
#include <vector>
#include<iterator>
using namespace std;

class tokenizer_t
{
public:
    tokenizer_t() {}
    virtual ~tokenizer_t() {}
    void tokenize(const string&);
    size_t getSize() const { return m_tokens.size(); }
    const string &getNextToken();
    const vector<string> &getVector() const { return m_tokens; }

private:
    tokenizer_t(const tokenizer_t &t);
    tokenizer_t &operator=(const tokenizer_t &t);
    static string s_tokenDelimiters;
    static string s_emptyString;
    vector<string> m_tokens;
    vector<string>::iterator m_nextToken;
};

#endif // !TOKENIZER_T_H
