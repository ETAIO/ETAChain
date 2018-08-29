The following steps must be taken for the example script to work.

0. Create wallet
0. Create account for ETAio.token
0. Create account for scott
0. Create account for exchange
0. Set token contract on ETAio.token
0. Create ETA token
0. Issue initial tokens to scott

**Note**:
Deleting the `transactions.txt` file will prevent replay from working.


### Create wallet
`clETA wallet create`

### Create account steps
`clETA create key`

`clETA create key`

`clETA wallet import  --private-key <private key from step 1>`

`clETA wallet import  --private-key <private key from step 2>`

`clETA create account ETAio <account_name> <public key from step 1> <public key from step 2>`

### Set contract steps
`clETA set contract ETAio.token /contracts/ETAio.token -p ETAio.token@active`

### Create ETA token steps
`clETA push action ETAio.token create '{"issuer": "ETAio.token", "maximum_supply": "100000.0000 ETA", "can_freeze": 1, "can_recall": 1, "can_whitelist": 1}' -p ETAio.token@active`

### Issue token steps
`clETA push action ETAio.token issue '{"to": "scott", "quantity": "900.0000 ETA", "memo": "testing"}' -p ETAio.token@active`
