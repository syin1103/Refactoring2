# 10.1 decompose conditional
add_executable(101charge 1_decompose_conditional/charge.cc) 
add_executable(101charge1 1_decompose_conditional/charge1.cc) 

# 10.2 consolidate conditional expression
add_executable(amount 2_consolidate_conditional_expression/amount.cc)
add_executable(amount1 2_consolidate_conditional_expression/amount1.cc)

# 10.3 replace nested conditional with guard clauses
add_executable(pay_amount 3_replace_nested_conditional_with_guard_clauses/pay_amount.cc)
add_executable(pay_amount1 3_replace_nested_conditional_with_guard_clauses/pay_amount1.cc)

# 10.4 replace conditional with polymorphism
add_executable(104bird 4_replace_conditional_with_polymorphism/bird.cc)
add_executable(104bird1 4_replace_conditional_with_polymorphism/bird1.cc)

# 10.5 introduce special case
add_executable(site 5_introduce_special_case/site.cc)
add_executable(site1 5_introduce_special_case/site1.cc)

# 10.6 introduce assertion
add_executable(discount 6_introduce_assertion/discount.cc)
add_executable(discount1 6_introduce_assertion/discount1.cc)