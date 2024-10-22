int to_lower_ascii(int c)
{
	return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}
