#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from collections import Counter

enc = list(map(int, open("data/p059_cipher.txt").read().strip().split(",")))

to_string = lambda x: "".join(map(chr, x))
to_ascii = lambda x: list(map(ord, x))

K = 3  # keylen
key = []
most_likely = " "  # frequency analysis on K splits

enc_splits = {k: enc[k::K] for k in range(K)}

for k in range(K):
    x, f = Counter(enc_splits[k]).most_common()[0]
    key.append(ord(most_likely) ^ x)

print(f"KEY: {to_string(key)} ({key})")

dec_splits = {k: list(map(lambda x: chr(key[k] ^ x), enc_splits[k])) for k in range(K)}

dec = [None] * len(enc)
for k in range(K):
    dec[k::K] = dec_splits[k]
dec = "".join(dec)

print(f"DECRYPTED: {dec}")
print(f"ASCII SUM: {sum(to_ascii(dec))}")
