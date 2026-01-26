class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


class SunlightError(GardenError):
    pass


class TankError(GardenError):
    pass


class GardenManager():
    def __init__(self):
        self.plants: dict[str, dict[str, int]] = {}
    
    
    def add_plant(
        self, 
        name: str,
        water_level: int,
        sunlight_hours: int,
        water_tank: int
    ) -> None:
        if not name:
            raise PlantError("Plant name cannot be empty!")
        self.plants[name] = {
            "water": water_level, 
            "sun": sunlight_hours, 
            "water_tank": water_tank
        }
    
    
    def water_plants(self) -> None:
        print("Opening watering system")
        try:
            for name in self.plants:
                print(f"Watering {name} - success")
        finally:
            print("Closing watering system {cleanup}\n")
    
    
    def check_health(
        self, 
        water_level: int,
        sunlight_hours: int,
    ) -> None:
        if water_level < 1:
            raise WaterError(f"Water level {water_level} is too low (min 1)")
        if water_level > 10:
            raise WaterError(f"Water level {water_level} is too high (max 10)")
        if sunlight_hours < 2:
            raise SunlightError(f"Sunlight hours {sunlight_hours} is too low (min 2)")
        if sunlight_hours > 12:
            raise SunlightError(f"Sunlight hours {sunlight_hours} is too high (max 12)")
    
    
    def check_tank(self) -> None:
        for name, info in self.plants.items():
            tank = info["water_tank"]
            if tank < 10:
                raise TankError("Error: Cannot water None - invalid plant!")
        print("enough water in tank")
            


def test_garden_management() -> None:
    gm = GardenManager()
    plants_to_add = [
        ("tomato", 5, 8, 11),
        ("lettuce", 15, 7, 32),
        ("", 3, 6, 50), 
    ]
    print("=== Garden Management System ===\n")
    
    print("Adding plants to garden...")
    for name, water_level, sunlight_hours, water_tank in plants_to_add:
        try:
            gm.add_plant(name, water_level, sunlight_hours, water_tank)
            print(f"Added {name} successfully")
        except GardenError as e:
            print(f"Error adding plant: {e}")
    print("\nWatering plants...")
    gm.water_plants()
    
    print("Checking plant health...")
    for name, info in gm.plants.items():
        try:
            gm.check_health(info["water"], info["sun"])
            print(f"{name}: healty (water: {info['water']}, sun: {info['sun']})")
        except GardenError as e:
            print(f"Error checking {name}: {e}")
            
    print("Testing error recovery...")
    try:
        gm.check_tank()
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print("System recovered and continuing...\n")
    print("Garden management system test complete!")
            
        
if __name__ == '__main__':
    test_garden_management()