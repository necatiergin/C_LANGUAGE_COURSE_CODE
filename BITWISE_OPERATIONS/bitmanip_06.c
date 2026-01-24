value is 0 or 1
assign the value to the kth bit

x = (x & ~(1u << k)) | ((unsigned)(bit & 1u) << k);
