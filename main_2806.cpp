#include "bits/stdc++.h"

using namespace std;

int accountBalanceAfterPurchase(int purchaseAmount) {
    return 100 - int(purchaseAmount / 10.0 + 0.5) * 10;
}