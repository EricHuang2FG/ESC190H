def change_num(a):
    a = 10
    # this is local

def change_char_arr(arr):
    arr[0] = 'd'

def main():
    num = 5
    change_num(5)
    print(num)

    char_arr = ['1', '2', '3']
    change_char_arr(char_arr)
    print(char_arr)

if __name__ == "__main__":
    main()
