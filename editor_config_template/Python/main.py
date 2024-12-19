MOD = 1000000007

def count_acceptable_words(word):
    n = len(word)
    result = 1
    arr = [[0] * 26 for _ in range(n)]

    for i in range(n):
      arr[i][ord(word[i]) - ord('a')] = 1

    for i in range(n):
      if i == 0:
        arr[i][ord(word[i]) - ord('a')] = 1
        arr[i][ord(word[i+1]) - ord('a')] = 1

      elif i == n - 1:
        arr[i][ord(word[i]) - ord('a')] = 1
        arr[i][ord(word[i-1]) - ord('a')] = 1
      
      else:
        arr[i][ord(word[i]) - ord('a')] = 1
        arr[i][ord(word[i-1]) - ord('a')] = 1
        arr[i][ord(word[i+1]) - ord('a')] = 1

    for i in range(n):
      result *= sum(arr[i])
    
    result %= MOD
    return int(result)


target_word = input().strip()
result = count_acceptable_words(target_word)
print(result)
