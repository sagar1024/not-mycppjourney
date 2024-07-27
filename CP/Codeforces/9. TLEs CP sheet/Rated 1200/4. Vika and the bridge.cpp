// B. Vika and the Bridge

// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// In the summer, Vika likes to visit her country house. There is everything for relaxation: comfortable swings, bicycles, and a river. There is a wooden bridge over the river, consisting of n planks. It is quite old and unattractive, so Vika decided to paint it. And in the shed, they just found cans of paint of k colors. After painting each plank in one of k colors, Vika was about to go swinging to take a break from work. However, she realized that the house was on the other side of the river, and the paint had not yet completely dried, so she could not walk on the bridge yet. In order not to spoil the appearance of the bridge, Vika decided that she would still walk on it, but only stepping on planks of the same color. Otherwise, a small layer of paint on her sole will spoil the plank of another color. Vika also has a little paint left, but it will only be enough to repaint one plank of the bridge. Now Vika is standing on the ground in front of the first plank. To walk across the bridge, she will choose some planks of the same color (after repainting), which have numbers 1≤i1<i2<…<im≤n (planks are numbered from 1 from left to right). Then Vika will have to cross i1−1,i2−i1−1,i3−i2−1,…,im−im−1−1,n−im planks as a result of each of m+1 steps. Since Vika is afraid of falling, she does not want to take too long steps. Help her and tell her the minimum possible maximum number of planks she will have to cross in one step, if she can repaint one (or zero) plank a different color while crossing the bridge.

// Input
// Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers n and k (1≤k≤n≤2⋅105) — the number of planks in the bridge and the number of different colors of paint. The second line of each test case contains n integers c1,c2,c3,…,cn (1≤ci≤k) — the colors in which Vika painted the planks of the bridge. It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the minimum possible maximum number of planks that Vika will have to step over in one step.

// Example
// inputCopy
// 5
// 5 2
// 1 1 2 1 1
// 7 3
// 1 2 3 3 3 2 1
// 6 6
// 1 2 3 4 5 6
// 8 4
// 1 2 3 4 2 3 1 4
// 3 1
// 1 1 1

// outputCopy
// 0
// 1
// 2
// 2
// 0

// Note
// In the first test case, Vika can repaint the plank in the middle in color 1 and walk across the bridge without stepping over any planks.
// In the second test case, Vika can repaint the plank in the middle in color 2 and walk across the bridge, stepping over only one plank each time.
// In the third test case, Vika can repaint the penultimate plank in color 2 and walk across the bridge, stepping only on planks with numbers 2 and 5. Then Vika will have to step over 1, 2 and 1 plank each time she steps, so the answer is 2.
// In the fourth test case, Vika can simply walk across the bridge without repainting it, stepping over two planks each time, walking on planks of color 3.
// In the fifth test case, Vika can simply walk across the bridge without repainting it, without stepping over any planks.

// My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int calculateMaxSteps(vector<int> &plankColors, int &k)
// {
//     int lastIdx = 0;
//     vector<int> steps;
//     for(int i=0; i<plankColors.size(); i++)
//     {
//         if(plankColors[i]==k)
//         {
//             steps.push_back(i-lastIdx);
//             lastIdx = i+1;
//         }
//     }

//     sort(steps.begin(), steps.end(), greater<int>());
//     int maxx1 = steps[0]/2;
//     int maxx2 = steps[1];

//     return max(maxx1,maxx2);
// }

// void solve()
// {
//     //Num of planks and colors
//     int n, k;
//     cin >> n >> k;

//     vector<int> plankColors(n);
//     for(int i=0; i<n; i++)
//     {
//         cin >> plankColors[i];
//     }

//     vector<int> maxStepsReq(k);
//     for(int i=1; i<=k; i++)
//     {
//         int x = calculateMaxSteps(plankColors,i);
//         maxStepsReq.push_back(x);
//     }

//     int ans = 0;
//     for(auto x: maxStepsReq)
//     {
//         ans = min(ans,x);
//     }

//     cout << ans << endl;
//     return;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;

//     while(t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln(tle on tc3) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int calculateMaxSteps(vector<int> &plankColors, int color, int n)
// {
//     int lastIdx = -1; //Initialize to -1 to handle the first segment correctly
//     vector<int> steps;
//     for (int i = 0; i < n; i++)
//     {
//         if (plankColors[i] == color)
//         {
//             if (lastIdx == -1)
//             {
//                 steps.push_back(i); //From the start to the first occurrence
//             }
//             else
//             {
//                 steps.push_back(i - lastIdx - 1); //Between occurrences
//             }

//             lastIdx = i;
//         }
//     }

//     if (lastIdx != -1)
//     {
//         steps.push_back(n - lastIdx - 1); //From the last occurrence to the end
//     }
//     if (steps.empty())
//     {
//         return n - 1; //If no planks of this color, the whole bridge needs to be crossed
//     }

//     sort(steps.begin(), steps.end(), greater<int>());

//     int maxStep = steps[0] / 2; //Divide the largest gap by 2 (painting one plank)
//     if (steps.size() > 1)
//     {
//         maxStep = max(maxStep, steps[1]); //Compare with the second largest gap
//     }

//     return maxStep;
// }

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> plankColors(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> plankColors[i];
//     }

//     int ans = n; //Initialize to the maximum possible value (crossing the whole bridge)
//     for (int i = 1; i <= k; i++)
//     {
//         ans = min(ans, calculateMaxSteps(plankColors, i, n));
//     }

//     cout << ans << endl;

//     return;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

// Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canCross(const vector<int> &plankColors, int k, int maxStep)
{
    int n = plankColors.size();
    for (int color = 1; color <= k; ++color)
    {
        int last = -1;
        int maxDist = 0;
        bool needsRepaint = false;

        for (int i = 0; i < n; ++i)
        {
            if (plankColors[i] == color)
            {
                if (last != -1)
                {
                    int dist = i - last - 1;
                    if (dist > maxStep)
                    {
                        needsRepaint = true;
                        break;
                    }

                    maxDist = max(maxDist, dist);
                }

                last = i;
            }
        }

        if (last != -1)
        {
            maxDist = max(maxDist, last - (-1) - 1); // Check from start to first occurrence
            maxDist = max(maxDist, n - last - 1);    // Check from last occurrence to end
        }

        if (maxDist <= maxStep)
        {
            return true; // Already feasible without repainting
        }

        if (needsRepaint)
        {
            int first = -1;
            last = -1;
            maxDist = 0;
            for (int i = 0; i < n; ++i)
            {
                if (plankColors[i] == color)
                {
                    if (first == -1) first = i;
                    last = i;
                }
            }

            int gap1 = last - first - 1;
            int gap2 = max(first, n - last - 1);
            if (gap1 <= maxStep && gap2 <= maxStep)
            {
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> plankColors(n);
    for (int i = 0; i < n; i++)
    {
        cin >> plankColors[i];
    }

    int left = 0, right = n, ans = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (canCross(plankColors, k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
