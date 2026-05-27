import math

def any_radix_to_dec(digg, base):
    ans = 0
    dig = len(digg)
    for i in range(dig - 1, -1, -1):
        ans += digg[dig - 1 - i] * (base ** i)
    print(f"The final answer is: {ans}\n")

def dec_to_any_radix(digg, base):
    combine = 0
    for d in digg:
        combine = combine * 10 + d
    
    ans = []
    if combine == 0:
        return [0]
        
    while combine > 0:
        ans.append(combine % base)
        combine //= base
    return ans  # Returns the list of remainders (reversed order)

def bin_to_oct(digg):
    oct_digits = ['0', '1', '2', '3', '4', '5', '6', '7']
    groupsiz = 3
    dig = len(digg)
    
    # Pad the binary list with leading zeros so its length is a multiple of 3
    padded_digg = digg.copy()
    while len(padded_digg) % 3 != 0:
        padded_digg.insert(0, 0)
        
    bin_oct_res = []
    # Process from left to right in chunks of 3
    for i in range(0, len(padded_digg), 3):
        val = 0
        for j in range(groupsiz):
            val = val * 2 + padded_digg[i + j]
        bin_oct_res.append(oct_digits[val])
        
    return bin_oct_res

def oct_to_bin(digg):
    binary_map = ["000", "001", "010", "011", "100", "101", "110", "111"]
    return [binary_map[d] for d in digg]

def bin_to_hexadec(digg):
    hexadec_digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    
    # Pad the binary list with leading zeros so its length is a multiple of 4
    padded_digg = digg.copy()
    while len(padded_digg) % 4 != 0:
        padded_digg.insert(0, 0)
        
    bin_hexadec_res = []
    for i in range(0, len(padded_digg), 4):
        val = 0
        for j in range(4):
            val = val * 2 + padded_digg[i + j]
        bin_hexadec_res.append(hexadec_digits[val])
        
    return bin_hexadec_res

def hexadec_to_bin(digg):
    binary_map = ["0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", 
                  "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"]
    return [binary_map[d] for d in digg]

def main():
    while True:
        print("List of Conversions")
        print("\n1.Binary -> Decimal\n2.Octal -> Decimal\n3.Hexa Decimal -> Decimal")
        print("4.Decimal -> Binary\n5.Decimal -> Octal\n6.Decimal -> Hexadecimal")
        print("7.Binary -> Octal\n8.Octal -> Binary")
        print("9.Binary -> Hexa Decimal\n10.Hexa Decimal -> Binary")
        print("11.Octal -> Hexa Decimal\n12.Hexa Decimal -> Octal")
        
        try:
            n = int(input("Enter number which Conversion you want - "))
        except ValueError:
            print("Please enter a valid choice.")
            continue

        if n == 1:
            print("You selected Binary -> Decimal")
            num_str = input("Enter the binary number: ").strip()
            digg = []
            valid = True
            for char in num_str:
                if char in ['0', '1']:
                    digg.append(int(char))
                else:
                    print("The binary number should contain 0 or 1 only.")
                    valid = False
                    break
            if valid:
                any_radix_to_dec(digg, 2)

        elif n == 2:
            print("You selected Octal -> Decimal")
            num_str = input("Enter the Octal number: ").strip()
            digg = []
            valid = True
            for char in num_str:
                if '0' <= char <= '7':
                    digg.append(int(char))
                else:
                    print("The Octal number should be between 0 to 7 only.")
                    valid = False
                    break
            if valid:
                any_radix_to_dec(digg, 8)

        elif n == 3:
            print("You selected Hexa Decimal -> Decimal")
            num_str = input("Enter the Hexa Decimal number: ").strip().lower()
            digg = []
            valid = True
            for char in num_str:
                if '0' <= char <= '9':
                    digg.append(int(char))
                elif 'a' <= char <= 'f':
                    digg.append(10 + (ord(char) - ord('a')))
                else:
                    print("The Hexa Decimal number should be 0-9 or a-f only.")
                    valid = False
                    break
            if valid:
                any_radix_to_dec(digg, 16)

        elif n == 4:
            print("You selected Decimal -> Binary")
            num_str = input("Enter the Decimal number: ").strip()
            if num_str.isdigit():
                digg = [int(char) for char in num_str]
                ans = dec_to_any_radix(digg, 2)
                print("The final answer is: ", " ".join(map(str, reversed(ans))), "\n")
            else:
                print("The decimal number should be digits between 0 to 9 only.")

        elif n == 5:
            print("You selected Decimal -> Octal")
            num_str = input("Enter the Decimal number: ").strip()
            if num_str.isdigit():
                digg = [int(char) for char in num_str]
                ans = dec_to_any_radix(digg, 8)
                print("The final answer is: ", "".join(map(str, reversed(ans))), "\n")
            else:
                print("The decimal number should be digits between 0 to 9 only.")

        elif n == 6:
            print("You selected Decimal -> Hexa Decimal")
            num_str = input("Enter the Decimal number: ").strip()
            if num_str.isdigit():
                digg = [int(char) for char in num_str]
                ans = dec_to_any_radix(digg, 16)
                print("The final answer is: ", end="")
                for val in reversed(ans):
                    if 10 <= val <= 15:
                        print(chr(ord('A') + (val - 10)), end="")
                    else:
                        print(val, end="")
                print("\n")
            else:
                print("The decimal number should be digits between 0 to 9 only.")

        elif n == 7:
            print("You selected Binary -> Octal")
            num_str = input("Enter the binary number: ").strip()
            if len(num_str) >= 3 and all(c in '01' for c in num_str):
                digg = [int(c) for c in num_str]
                res = bin_to_oct(digg)
                print("The final answer is:", " ".join(res), "\n")
            else:
                print("Invalid input. Must be digits of 0 or 1, and length >= 3.\n")

        elif n == 8:
            print("You selected Octal -> Binary")
            num_str = input("Enter the Octal number: ").strip()
            if all('0' <= c <= '7' for c in num_str):
                digg = [int(c) for c in num_str]
                res = oct_to_bin(digg)
                print("The final answer is:", " ".join(res), "\n")
            else:
                print("The Octal number should be between 0 and 7 only.\n")

        elif n == 9:
            print("You selected Binary -> Hexa Decimal")
            num_str = input("Enter the binary number: ").strip()
            if len(num_str) >= 4 and all(c in '01' for c in num_str):
                digg = [int(c) for c in num_str]
                res = bin_to_hexadec(digg)
                print("The final answer is:", "".join(res), "\n")
            else:
                print("Invalid input. Must be digits of 0 or 1, and length >= 4.\n")

        elif n == 10:
            print("You selected Hexa Decimal -> Binary")
            num_str = input("Enter the Hexa Decimal number: ").strip().lower()
            valid = True
            digg = []
            for char in num_str:
                if '0' <= char <= '9':
                    digg.append(int(char))
                elif 'a' <= char <= 'f':
                    digg.append(10 + (ord(char) - ord('a')))
                else:
                    valid = False
                    break
            if valid and num_str:
                res = hexadec_to_bin(digg)
                print("The final answer is:", " ".join(res), "\n")
            else:
                print("Invalid Hexadecimal format.\n")

        elif n == 11:
            print("You selected Octal -> Hexa Decimal")
            num_str = input("Enter the Octal number: ").strip()
            if all('0' <= c <= '7' for c in num_str):
                # Octal to intermediate binary array logic (3 bits per octal digit)
                oct_bin_res = []
                for c in num_str:
                    val = int(c)
                    # Break down into 3 bits manually matching your logic
                    b1 = val // 4
                    b2 = (val % 4) // 2
                    b3 = val % 2
                    oct_bin_res.extend([b1, b2, b3])
                
                res = bin_hexadec_res = bin_to_hexadec(oct_bin_res)
                print("The final answer is:", "".join(res), "\n")
            else:
                print("The Octal number should be between 0 to 7 only.\n")

        elif n == 12:
            print("You selected Hexa Decimal -> Octal")
            num_str = input("Enter the Hexa Decimal number: ").strip().lower()
            digg = []
            valid = True
            for char in num_str:
                if '0' <= char <= '9':
                    digg.append(int(char))
                elif 'a' <= char <= 'f':
                    digg.append(10 + (ord(char) - ord('a')))
                else:
                    valid = False
                    break
            if valid and num_str:
                # Hexadecimal to intermediate binary array logic (4 bits per hex digit)
                hexadec_bin_res = []
                for val in digg:
                    b1 = val // 8
                    b2 = (val % 8) // 4
                    b3 = (val % 4) // 2
                    b4 = val % 2
                    hexadec_bin_res.extend([b1, b2, b3, b4])
                
                res = bin_to_oct(hexadec_bin_res)
                print("The final answer is:", "".join(res), "\n")
            else:
                print("Invalid Hexadecimal input.\n")

if __name__ == "__main__":
    main()