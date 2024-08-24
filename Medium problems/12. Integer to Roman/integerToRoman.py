class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """

        roman = [
            ("I" , 1),
            ("V" , 5),
            ("X" , 10),
            ("L" , 50),
            ("C" , 100),
            ("D" , 500),
            ("M" , 1000),
        ]
        subtractive_form = {
            4 : "IV",
            9 : "IX",
            40 : "XL",
            90 : "XC",
            400 : "CD",
            900 : "CM"
        }

        i = len(roman) - 1
        result = ""

        while (i >= 0):

            str_num = str(num)
            if(str_num[0] == '4' or str_num[0] == '9'):

                dec = len(str_num) - 1
                cor = int(str_num[0] + '0' * dec)

                result = result + subtractive_form[int(cor)]

                num = num - cor
            else:
                number_of_symbol = num / roman[i][1]
                num = num - (num / roman[i][1]) * roman[i][1]
                
                result = result + roman[i][0] * number_of_symbol
            
            i = i - 1

        return result