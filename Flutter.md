# Flutter

## Key

1. `CanUpdate()` check both the runtime and key. If it returns true, then we do not need to replace the element but only rebuild it. Else we need to replace the element or contruct a new one.

2. When it finds the key is changed, Flutter would go through all the widgets that are on the same *children level* (all the children of a same root). If it finds corresponding key then it replace with that. Otherwise, it construct with a new one.
    1. **Point**: It only search through the child level. If the corresponding key is on another subtree, then it cannot be found.


## Layouts

1. `Center and Container` has single child and they have `child` property. `Row, Column, ListView and Stack` have `children` property.


## Json

1. create user.dart file to generate the json en/decoder
```dart
import 'package:json_annotation/json_annotation.dart';

/// This allows the `User` class to access private members in
/// the generated file. The value for this is *.g.dart, where
/// the star denotes the source file name.
part 'user.g.dart';

/// An annotation for the code generator to know that this class needs the
/// JSON serialization logic to be generated.
@JsonSerializable()

class User {
  User(this.name, this.email);

  String name;
  String email;

  /// A necessary factory constructor for creating a new User instance
  /// from a map. Pass the map to the generated `_$UserFromJson()` constructor.
  /// The constructor is named after the source class, in this case User.
  factory User.fromJson(Map<String, dynamic> json) => _$UserFromJson(json);

  /// `toJson` is the convention for a class to declare support for serialization
  /// to JSON. The implementation simply calls the private, generated
  /// helper method `_$UserToJson`.
  Map<String, dynamic> toJson() => _$UserToJson(this);

  /// Tell json_serializable that "registration_date_millis" should be
  /// mapped to this property.
  @JsonKey(name: 'registration_date_millis')
  final int registrationDateMillis;
}
```

2. two ways to generate the code
    1. one-time: `flutter pub run build_runner build`
    2. continuous: `flutter pub run build_runner watch`

3. how to use
```dart
import 'dart:convert';
import '.../user.dart';

// decode
Map userMap = jsonDecode(jsonString);
var user = User.fromJson(userMap);

// encode
String json = jsonEncode(user);
```