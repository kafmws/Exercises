#include <bits/stdc++.h>
#ifdef _KFAM_
#include <windows.h>
// split to make windows.h before psapi.h
#include <psapi.h>
#endif
#define all(a) std::begin(a), std::end(a)
#define rall(a) std::rbegin(a), std::rend(a)
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }
#define YESNO(condition) if(condition)cout<<"YES\n";else cout<<"NO\n";
using std::cin, std::cout,std::endl;
auto tam = [] {std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifdef _KFAM_
#define CHECKTIME tam.stop()
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);struct TIME_AND_MEMORY {static auto GetMicroSecond() {static FILETIME ft;GetSystemTimeAsFileTime(&ft);return ft.dwLowDateTime;};static auto GetMemory() {PROCESS_MEMORY_COUNTERS pmc;GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));return pmc.WorkingSetSize;}uint32_t t0, t1;TIME_AND_MEMORY() : t0(GetMicroSecond()) {}void stop() {t1 = GetMicroSecond();cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";t0 = t1;}~TIME_AND_MEMORY() { stop(); }};return TIME_AND_MEMORY();
#else
#define CHECKTIME
    return 0;
#endif
}();

#if __cplusplus == 201703L
#define tst 132
#endif

int main() {
    int t;cin>>t;
    while(t--){
        int n;
        std::string s;
        cin>>n>>s;
        std::sort(all(s));
        YESNO(s=="Timru");
    }

    CHECKTIME;
}