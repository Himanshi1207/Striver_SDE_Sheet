#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

bool isdivided(vector<int> positions, int n, int c, int mid)

{

    int rmcnt = positions[0];

    int player = 1;

    for (int i = 0; i < n; i++)

    {

        // is distnace mid enough and all players are allocated with rtheir room or not

        if (positions[i] - rmcnt >= mid)

        {

            player++;

            if (player == c)

            {

                return true;
            }

            rmcnt = positions[i];
        }
    }

    return false;
}

int chessTournament(vector<int> positions, int n, int c)
{

    // Write your code here

    sort(positions.begin(), positions.end());

    int maxi = -1;

    for (int i = 0; i < n; i++)

    {

        maxi = max(maxi, positions[i]);
    }

    int ans = -1;

    int s = 1;

    int e = maxi;

    // FUNCTION TO CHECK THAT IS IT POSSIBLE KEEP THE PLAYER MID DISTANCE AHEAD

    // IF YES THEN CHECK FOR IS MID CAN BE MORE

    // IF NO THEM REDUCE THE DISTANCE BETWEEN TWO PLAYER

    while (s <= e)

    {

        // start with maximum seperation btwn 2 players

        int mid = s + (e - s) / 2;

        if (isdivided(positions, n, c, mid))

        {

            ans = mid;

            s = mid + 1;
        }

        // if dist mid is not satisfied then we reduce it

        else

        {

            e = mid - 1;
        }
    }

    return ans;
}