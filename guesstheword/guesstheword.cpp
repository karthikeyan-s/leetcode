/***
https://leetcode.com/problems/guess-the-word/description/
***/

#include <stdio.h>
#include <malloc.h>

typedef struct Master {

}Master;

#if 0
const char *gsecret = "hbaczn";
const char *gwordlist[] = { "gaxckt", "trlccr", "jxwhkz", "ycbfps", "peayuf", "yiejjw", "ldzccp", 
							"nqsjoa", "qrjasy", "pcldos", "acrtag", "buyeia", "ubmtpj", "drtclz", 
							"zqderp", "snywek", "caoztp", "ibpghw", "evtkhl", "bhpfla", "ymqhxk", 
							"qkvipb", "tvmued", "rvbass", "axeasm", "qolsjg", "roswcb", "vdjgxx", 
							"bugbyv", "zipjpc", "tamszl", "osdifo", "dvxlxm", "iwmyfb", "wmnwhe", 
							"hslnop", "nkrfwn", "puvgve", "rqsqpq", "jwoswl", "tittgf", "evqsqe", 
							"aishiv", "pmwovj", "sorbte", "hbaczn", "coifed", "hrctvp", "vkytbw", 
							"dizcxz", "arabol", "uywurk", "ppywdo", "resfls", "tmoliy", "etriev", 
							"oanvlx", "wcsnzy", "loufkw", "onnwcy", "novblw", "mtxgwe", "rgrdbt", 
							"ckolob", "kxnflb", "phonmg", "egcdab", "cykndr", "lkzobv", "ifwmwp", 
							"jqmbib", "mypnvf", "lnrgnj", "clijwa", "kiioqr", "syzebr", "rqsmhg", 
							"sczjmz", "hsdjfp", "mjcgvm", "ajotcx", "olgnfv", "mjyjxj", "wzgbmg", 
							"lpcnbj", "yjjlwn", "blrogv", "bdplzs", "oxblph", "twejel", "rupapy", 
							"euwrrz", "apiqzu", "ydcroj", "ldvzgq", "zailgu", "xgqpsr", "wxdyho", 
							"alrplq", "brklfk" };
#else
const char *gsecret = "ccoyyo";
const char *gwordlist[] = { "wichbx", "oahwep", "tpulot", "eqznzs", "vvmplb", "eywinm", "dqefpt", 
"kmjmxr", "ihkovg", "trbzyb", "xqulhc", "bcsbfw", "rwzslk", "abpjhw", "mpubps", "viyzbc", "kodlta", 
"ckfzjh", "phuepp", "rokoro", "nxcwmo", "awvqlr", "uooeon", "hhfuzz", "sajxgr", "oxgaix", "fnugyu", 
"lkxwru", "mhtrvb", "xxonmg", "tqxlbr", "euxtzg", "tjwvad", "uslult", "rtjosi", "hsygda", "vyuica", 
"mbnagm", "uinqur", "pikenp", "szgupv", "qpxmsw", "vunxdn", "jahhfn", "kmbeok", "biywow", "yvgwho", 
"hwzodo", "loffxk", "xavzqd", "vwzpfe", "uairjw", "itufkt", "kaklud", "jjinfa", "kqbttl", "zocgux", 
"ucwjig", "meesxb", "uysfyc", "kdfvtw", "vizxrv", "rpbdjh", "wynohw", "lhqxvx", "kaadty", "dxxwut", 
"vjtskm", "yrdswc", "byzjxm", "jeomdc", "saevda", "himevi", "ydltnu", "wrrpoc", "khuopg", "ooxarg", 
"vcvfry", "thaawc", "bssybb", "ccoyyo", "ajcwbj", "arwfnl", "nafmtm", "xoaumd", "vbejda", "kaefne", 
"swcrkh", "reeyhj", "vmcwaf", "chxitv", "qkwjna", "vklpkp", "xfnayl", "ktgmfn", "xrmzzm", "fgtuki", 
"zcffuv", "srxuus", "pydgmq" };
#endif

int gcheck(const char* s1, const char* s2)
{
	int ret, i;
	ret = 0;
	for (i = 0; i < 6; i++) {
		if (s1[i] == s2[i]) ret++;
	}
	return ret;
}

int guesscnt;
int guess(Master *, char *word)
{
	guesscnt++;
	return gcheck(word, gsecret);
}

void findSecretWord(char** wordlist, int wordlistSize, Master* master);

int main()
{
	Master master;
	guesscnt = 0;
	findSecretWord((char**)gwordlist, sizeof(gwordlist)/sizeof(*gwordlist), &master);
	printf("number of guess=%d\n", guesscnt);
    return 0;
}

/*
"hbaczn"
["gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw","ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz","zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb","tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc","tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve","rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn","coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls","tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe","rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp","jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz","hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn","blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj","ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk"]
10
*/

/**
* *********************************************************************
* // This is the Master's API interface.
* // You should not implement it, or speculate about its implementation
* *********************************************************************
*
* int guess(Master *, char *word);
*/

unsigned char *invalid;
int *count;

int check(const char* s1, const char* s2)
{
	int ret, i;
	ret = 0;
	for (i = 0; i < 6; i++) {
		if (s1[i] == s2[i]) ret++;
	}
	return ret;
}

void findSecretWord(char** wordlist, int wordlistSize, Master* master) {
	int i, j, k;
	int matches, minval, minidx;
	invalid = (unsigned char*)calloc(wordlistSize, sizeof(unsigned char));
	
	for (i = 0; i < 11; i++) {

#if 0
		j = 0;
		while ((j < wordlistSize) && (invalid[j] == 1)) ++j;

		if (j >= wordlistSize) {
			free(invalid);
			return;
		}
#else
		count = (int*)calloc(wordlistSize, sizeof(int));
		for (j = 0; j < wordlistSize; j++) {
			if (invalid[j] == 1) continue;
			for (k = 0; k < j; k++) {
				if ( (invalid[k]==0) && (check(wordlist[j], wordlist[k]) == 0)) count[j]++;
			}
			for (k = j+1; k < wordlistSize; k++) {
				if ((invalid[k] == 0) && (check(wordlist[j], wordlist[k]) == 0)) count[j]++;
			}
		}
		minval = wordlistSize;
		for (j = 0; j < wordlistSize; j++) {
			if (invalid[j] == 0) {
				if (count[j] < minval) {
					minval = count[j];
					minidx = j;
				}
			}
		}
		j = minidx;
		free(count);
#endif

		matches = guess(master, wordlist[j]);
		printf("Iter:%d pos:%d match:%d\n", i, j, matches);
		if (matches == 6) {
			free(invalid);
			return;
		}

		invalid[j] = 1;
		k = 0;
		while (k < wordlistSize) {
			if ((invalid[k] == 0)) {
				if (check(wordlist[j],wordlist[k]) != matches) invalid[k] = 1;
			}
			++k;
		}
	}
	free(invalid);
}
