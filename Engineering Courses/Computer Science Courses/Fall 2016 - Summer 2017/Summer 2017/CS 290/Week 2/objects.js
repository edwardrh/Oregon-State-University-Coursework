function deepEqual(x, y){
	var countx = 0;
	for(p in x){
		countx += 1;
	}
	var county = 0;
	for(p in y){
		county += 1;
	}
	if(countx != county){
		return false;
	}
	else{
		var a = x + y;
		var valuex;
		var valuey;
		for(p in a){
			valuex = a[p];
			valuey = a[countx + p];
			if(typeof(valuex) === typeof(valuey)){
				if(typeof(valuex) == "object" && typeof(valuey) == "object"){
					if(valuex == null && valuey != null){
						return false;
					}
					else if(valuex != null && valuey == null){
						return false;
					}
				}
			}
			else{
				return false;
			}
		}
		return true;
	}
}