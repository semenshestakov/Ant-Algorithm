typedef unordered_set<HashablePointPtr, HashablePoint::SharedPtrHash, HashablePoint::SharedPtrEqual> setPoint;

typedef unordered_map<HashablePointPtr, unordered_map<HashablePointPtr, PointToPoint, HashablePoint::SharedPtrHash, HashablePoint::SharedPtrEqual>, HashablePoint::SharedPtrHash, HashablePoint::SharedPtrEqual> mapPoint;

typedef std::shared_ptr< mapPoint > mapPointPtr;
