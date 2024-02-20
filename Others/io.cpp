#include <bits/stdc++.h>

using namespace std;
#define OPENIOBUF

namespace FastIO
{

class FastIOBase
{
protected:
#ifdef OPENIOBUF
	static const int BUFSIZE = 1 << 16;
	char buf[BUFSIZE + 1];
	int buf_p = 0;
#endif
	FILE *target;
	FastIOBase(FILE *f): target(f) {}
	~FastIOBase() = default;
public:
#ifdef OPENIOBUF
	virtual void flush() = 0;
#endif
};

class FastOutput final: public FastIOBase
{
private:
	void __putc(char x)
	{
#ifdef OPENIOBUF
		if (buf[buf_p++] = x, buf_p == BUFSIZE) flush();
#else
		putc(x, target);
#endif
	}
	template<typename T>
	void __write(T x)
	{
		char stk[numeric_limits<T>::digits10 + 1], *top = stk;
		if (x < 0) return __putc('-'), __write(-x);
		do *(top++) = x % 10, x /= 10; while (x);
		for (; top != stk; __putc(*(--top) + '0'));
	}
public:
	FastOutput(FILE *f = stdout): FastIOBase(f) {}
#ifdef OPENIOBUF
	~FastOutput() { flush(); }
	void flush() { fwrite(buf, 1, buf_p, target), buf_p = 0; }
#endif
	FastOutput &operator <<(char x)
	{ return __putc(x), *this; }
	FastOutput &operator <<(const char *s)
	{ for (; *s; __putc(*(s++))); return *this; }
	FastOutput &operator <<(const std::string &s)
	{ return (*this) << s.c_str(); }
	template<typename T>
	std::enable_if_t<std::is_integral<T>::value, FastOutput&> operator <<(const T &x)
	{ return __write(x), *this; }
	template<typename ...T>
	void writesp(const T &...x)
	{ std::initializer_list<int> {(this->operator<<(x), __putc(' '), 0)...}; }
	template<typename ...T>
	void writeln(const T &...x)
	{ std::initializer_list<int> {(this->operator<<(x), __putc('\n'), 0)...}; }
	template<typename Iter>
	void writesp(Iter begin, Iter end)
	{ while (begin != end) (*this) << *(begin++) << ' '; }
	template<typename Iter>
	void writeln(Iter begin, Iter end)
	{ while (begin != end) (*this) << *(begin++) << '\n'; }
} qout;

class FastInput final: public FastIOBase
{
private:
	bool __eof;
public:
	FastInput(FILE *f = stdin): FastIOBase(f), __eof(false)
#ifdef OPENIOBUF
	{ buf_p = BUFSIZE; }
	void flush() { buf[fread(buf, 1, BUFSIZE, target)] = EOF, buf_p = 0; }
	bool eof()const { return buf[buf_p] == EOF; }
#else
	{}
	bool eof()const { return feof(target); }
#endif
	char get()
	{
		if (__eof) return EOF;
#ifdef OPENIOBUF
		if (buf_p == BUFSIZE) flush();
		char ch = buf[buf_p++];
#else
		char ch = getc(target);
#endif
		return ~ch ? ch : (__eof = true, EOF);
	}
	void unget(char c)
	{
		__eof = false;
#ifdef OPENIOBUF
		buf[--buf_p] = c;
#else
		ungetc(c, target);
#endif
	}
	explicit operator bool()const { return !__eof; }
	FastInput &operator >>(char &x)
	{ while (isspace(x = get())); return *this; }
	template<typename T>
	std::enable_if_t<std::is_integral<T>::value, FastInput&> operator >>(T &x)
	{
		char ch, sym = 0; x = 0;
		while (isspace(ch = get()));
		if (__eof) return *this;
		if (ch == '-') sym = 1, ch = get();
		for (; isdigit(ch); x = (x << 1) + (x << 3) + (ch ^ 48), ch = get());
		return unget(ch), sym ? x = -x : x, *this;
	}
	FastInput &operator >>(char *s)
	{
		while (isspace(*s = get()));
		if (__eof) return *this;
		for (; !isspace(*s) && !__eof; * (++s) = get());
		return unget(*s), *s = '\0', *this;
	}
	FastInput &operator >>(std::string &s)
	{
		char str_buf[(1 << 8) + 1] = {0}, *p = str_buf;
		char *const buf_end = str_buf + (1 << 8);
		while (isspace(*p = get()));
		if (__eof) return *this;
		for (s.clear(), p++;; p = str_buf)
		{
			for (; p != buf_end && !isspace(*p = get()) && !__eof; p++);
			if (p != buf_end) break;
			s.append(str_buf);
		}
		unget(*p), *p = '\0', s.append(str_buf);
		return *this;
	}
	template<typename ...T>
	void read(T &...x)
	{ std::initializer_list<int> {(this->operator>>(x), 0)...}; }
	template<typename Iter>
	void read(Iter begin, Iter end)
	{ while (begin != end) (*this) >> *(begin++); }
} qin;

} // namespace FastIO
using FastIO::qin;
using FastIO::qout;

int main()
{
	int n;
	while (1)
	{
		qin >> n;
		if (n == 0) break;
		qout << n << ' ';
	}
	return 0;
}