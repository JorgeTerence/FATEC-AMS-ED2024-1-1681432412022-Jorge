|                  | Busca Linear | Busca Linear Ordenada | Busca Binária |
| ---------------- | ------------ | --------------------- | ------------- |
| $$x \in A$$      |              |                       | `9 * logs(n)` |
| $$x=A[1]$$       | `5t`         |                       | `10 * logs(n)` |
| $$x=A[n]$$       | `5tn+2t`     |                       | `8 * logs(n)` |
| $$x ~\not\in A$$ | `5tn+2t`     | `5t` ou `8tn + 2t `   | `8 * logs(n)` |

## Busca Linear

```py
i = 1 # t
while i <= n: # tn
    if A[i] == x: # 2tn
        return i # t
    i = i + 1 # 2tn
return -1 # t
```

## Busca Linear Ordenada

```py
i = 1 # t
while i <= n and x >= A[i]: # 4tn
    if A[i] == x: # 2tn
        return i # t
    i = i + 1 # 2tn
return -1 # t
```

## Busca Binária

```py
esq = 1 # t
dir = n # t
while esq <= dir: # tn
    meio = floor((esq + dir) / 2) # 3tn + ?tn
    if A[meio] == x: # 2tn
        return meio # t
    elif x > A[meio]: # 2tn
        esq = meio + 1 # 2tn
    else:
        dir = meio - 1 # 2tn
return -1 # t
```
