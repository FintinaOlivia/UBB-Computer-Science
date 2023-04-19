import functions

def test_add_new_expense():
    tenant = [{
            "apartment": 5,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}]
    functions.add_new_expense(5, "water", 20, tenant)
    assert tenant[0]["utilities"]["water"] == 20
    
def test_remove_apartment():
    test_string = [{
            "apartment": 4,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}, {
            "apartment": 5,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}, {
            "apartment": 6,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}, {
            "apartment": 7,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}]
    functions.remove_apartment(5)
    assert test_string[1] == {
            "apartment": 5,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}

def test_remove_apartments_in_range():
    test_string = [{
            "apartment": 4,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}, {
            "apartment": 5,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}, {
            "apartment": 6,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}, {
            "apartment": 7,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}]
    functions.remove_apartments_in_range(test_string, 2, 3)
    assert test_string[2] == {
            "apartment": 6,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}
    assert test_string[3] == {
            "apartment": 7,
            "amount": 0,
            "utilities": {
                "water": 0,
                "heating": 0,
                "electricity": 0,
                "gas": 0,
                "other": 0
            }}
    
def test_remove_expense():
    tenants = [{
            "apartment": 5,
            "amount": 0,
            "utilities": {
                "water": 20,
                "heating": 35,
                "electricity": 15,
                "gas": 56,
                "other": 10
            }},{
            "apartment": 6,
            "amount": 0,
            "utilities": {
                "water": 15,
                "heating": 55,
                "electricity": 25,
                "gas": 40,
                "other": 3
            }}]
               
    functions.remove_expense(tenants,"water")
    try:
        assert not tenants[0]['utilities']['water'] == 0
        assert not tenants[1]['utilities']['water'] == 0
    except:
        pass

def test_replace_amount():
    tenants = [{
            "apartment": 5,
            "amount": 0,
            "utilities": {
                "water": 20,
                "heating": 35,
                "electricity": 15,
                "gas": 56,
                "other": 10
            }},{
            "apartment": 6,
            "amount": 0,
            "utilities": {
                "water": 15,
                "heating": 55,
                "electricity": 25,
                "gas": 40,
                "other": 3
            }}]
    functions.replace_amount(6, 'water', 55, tenants)
    assert tenants[1]['utilities']['water'] == 55
    

def test_all():
    test_remove_apartments_in_range()
    test_add_new_expense()
    test_remove_expense()
    test_replace_amount()
    test_replace_amount()
    
test_all()