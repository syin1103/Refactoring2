# 12.1 pull up method
add_executable(party 1_pull_up_method/party.cc)
add_executable(party1 1_pull_up_method/party1.cc)

# 12.2 pull up field
add_executable(employee 2_pull_up_field/employee.cc)
add_executable(employee1 2_pull_up_field/employee1.cc)

# 12.3 pull up constructor body
add_executable(3_party 3_pull_up_constructor_body/party.cc)
add_executable(3_party1 3_pull_up_constructor_body/party1.cc)
add_executable(3_employee 3_pull_up_constructor_body/employee.cc)
add_executable(3_employee1 3_pull_up_constructor_body/employee1.cc)

# 12.4 push down method
add_executable(4_employee 4_push_down_method/employee.cc)
add_executable(4_employee1 4_push_down_method/employee1.cc)

# 12.5 push down field
add_executable(5_employee 5_push_down_field/employee.cc)
add_executable(5_employee1 5_push_down_field/employee1.cc)

# 12.6 replace type code with subclasses
add_executable(6_employee 6_replace_type_code_with_subclasses/employee.cc)
add_executable(6_employee1 6_replace_type_code_with_subclasses/employee1.cc)
add_executable(6_employee2 6_replace_type_code_with_subclasses/employee2.cc)

# 12.7 remove subclass
add_executable(person 7_remove_subclass/person.cc)
add_executable(person1 7_remove_subclass/person1.cc)

# 12.8 extract superclass
add_executable(department 8_extract_superclass/department.cc)
add_executable(department1 8_extract_superclass/department1.cc)

# 12.9 collapse hierarchy
add_executable(9_employee 9_collapse_hierarchy/employee.cc)
add_executable(9_employee1 9_collapse_hierarchy/employee1.cc)

# 12.10 replace subclass with delegate
add_executable(booking 10_replace_subclass_with_delegate/booking.cc)
add_executable(booking1 10_replace_subclass_with_delegate/booking1.cc)