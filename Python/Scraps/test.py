nums = ["", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"]
count = ["", "nghìn", "triệu", "tỉ"]

def readThreeDigitsNumber(number):
    hundred = number // 100
    dozen = (number % 100) // 10
    unit = number % 10
    result = ""
    
    if hundred > 0:
        result += nums[hundred] + " trăm "
        if dozen == 0 and unit > 0:
            result += "lẻ "
    
    if dozen > 1:
        result += nums[dozen] + " mươi "
        if unit == 1:
            result += "mốt "
        elif unit == 5:
            result += "lăm "
        else:
            result += nums[unit]
    elif dozen == 1:
        result += "mười "
        if unit == 5:
            result += "lăm"
        else:
            result += nums[unit]
    elif unit > 0:
        result += nums[unit]
    
    return result.strip()

def readNumber(number):
    if number == 0:
        return "không"
    
    result = ""
    index_count = 0

    while number > 0:
        ThreeDigitsNumber = number % 1000
        if ThreeDigitsNumber > 0:
            result = readThreeDigitsNumber(ThreeDigitsNumber) + " " + count[index_count] + " " + result
        number //= 1000
        index_count += 1

    return result.strip()

number = int(input("Enter: "))
print(readNumber(number))
