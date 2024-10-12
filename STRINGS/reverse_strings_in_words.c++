Problem statement
You are given a string 'str' of length 'N'.



Your task is to reverse the original string word by word.



There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.



Example :
If the given input string is "Welcome to Coding Ninjas", then you should return "Ninjas Coding to Welcome" as the reversed string has only a single space between two words and there is no leading or trailing space.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Explanation For Sample Input 1:
You need to reduce multiple spaces between two words to a single space in the reversed string and observe how the multiple spaces, leading and trailing spaces have been removed.
Sample Input 2 :
I am a star
Sample Output 2:
star a am I
Explanation For Sample Input 2:
Your reversed string should not contain leading or trailing spaces.



string reverseString(string &str){
	// Write your code here.
	string s;
	int i=str.length()-1;
	string temp="";
	while(i>=0){
		if(str[i]!=' '){
			temp+=str[i];
			
		}
		else{
			if(!temp.empty()){
				reverse(temp.begin(),temp.end());
				s+=temp+" ";
				temp="";
			}
		}
		i--;
	}

	if(!temp.empty()){
		reverse(temp.begin(),temp.end());
		s+=temp;
	}
	return s;
}
