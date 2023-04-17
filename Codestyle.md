# libnekoxx Codestyle

- Follow most parts of Linux Kernel Codestyle.
- TABs are 8-character wide, and do not expand them into spaces.
- Align assignments if possible.
- `type &func()` or `type *func()`, not `type& func()` or `type* func()`.
- Put a space between `operator` and the operator.
- Put a space between `new`/`delete` and `[]`
- Comment a line with `//`, comment a block of code with `/* */`
- Mark the end of a namespace or `#if` block with single line comments, e.g.,
```
#if __GNUC__
#endif	// __GNUC__

namespace std {
};	// std
```
