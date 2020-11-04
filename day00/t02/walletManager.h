#pragma once

struct Wallet {
    int septims;
};

Wallet* createWallet(int septims);

void destroyWallet(Wallet* wallet);

Wallet* createWallets(int size);

void destroyWallets(Wallet* wallets);
