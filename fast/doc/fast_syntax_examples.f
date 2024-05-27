Persistance
{
  Firebird.Server = server;
  Firebird.Database = db_alias;
}

C AsOfDate<C0 ...> // User does not need to write this, is part of DateUtil namespace.
{
	ReversibleHashMap<<Range<Date>, [C0 ...]> as RangeMap periods
	add  (Range<Date> range, [C0 ...])
	find (Query) RangeMap
}

// All CRUD methods for attributes created by compiler: find, add, remove, replace.
C PersonName u
{
	String first_name
	String middle_name
	String last_name
	name String { firstname + (middle_name ? ' ' + middle_name : (last_name ? ' ' + last_name)))} // function name which returns a String;
																						// Last statement defines return value. result can be used too.
}

C CompanyName
{
  String name
  List<String> aliases
  String description
}

E ContactInfoQualifier {ciHome, ciWork, ciOther}

C ContactInfo
{
	Address     address
	PhoneNumber phone_number
	Email       email
	URL         website
}
ContactInfoQualifier -* ContactInfo u AsOfDate ContactList; // Or manually: HashMap<ContactInfoQualifier, ContactInfo> as ContactList;

C OrganizationUnit u ContactList
{
	String name;
	String description;
}

C Company i OrganizationUnit
{
	List<String> aliases
}

C Role
{
	String name
	String description
}	

C Person u PersonName;

Role *-* Company u AsOfDate JobRole
Person *-* JobRole