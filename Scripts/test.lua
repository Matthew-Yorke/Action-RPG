Weapons =
{
  Sword =
  {
    name = "sword",
    damage = 1
  },
  Axe =
  {
    name = "axe",
    damage = 2
  }
}

for k, v in pairs(Weapons) do
    print(v.name, v.damage)
end