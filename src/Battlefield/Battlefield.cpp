#include "Battlefield/Battlefield.hpp"

Battlefield::Battlefield()
{
    for (int i = 0; i < this->getFieldSize(); ++i)
    {
        for (int j = 0; j < this->getFieldSize(); ++j)
        {
            field[i][j] = nullptr;
        }
    }
}

Battlefield::~Battlefield()
{
    for (int i = 0; i < this->getFieldSize(); ++i)
    {
        for (int j = 0; j < this->getFieldSize(); ++j)
        {
            field[i][j].reset();
            field[i][j] = nullptr;
        }
    }
}

std::shared_ptr<NPC> (&Battlefield::getField())[100][100]
{
    return field;
}

void Battlefield::placeNPC(std::shared_ptr<NPC> npc)
{
    if (!npc)
        return;
    int x = npc->getPosition().x;
    int y = npc->getPosition().y;
    if (x >= 0 && x < this->getFieldSize() && y >= 0 && y < this->getFieldSize())
    {
        field[x][y] = npc;
    }
}

std::shared_ptr<NPC> Battlefield::getNPC(int x, int y) const
{
    if (x >= 0 && x < this->getFieldSize() && y >= 0 && y < this->getFieldSize())
    {
        return field[x][y];
    }
    return nullptr;
}

void Battlefield::removeNPC(int x, int y)
{
    if (x >= 0 && x < this->getFieldSize() && y >= 0 && y < this->getFieldSize())
    {
        field[x][y] = nullptr;
    }
}

void Battlefield::findTargets(std::shared_ptr<NPC> npc, BattleVisitor &battleVisitor, std::vector<std::shared_ptr<NPC>> &targets)
{
    if (!npc)
        return;
    int attackDistance = npc->getAttackDistance();
    int startX = std::max(0, npc->getPosition().x - attackDistance);
    int endX = std::min(this->getFieldSize() - 1, npc->getPosition().x + attackDistance);
    int startY = std::max(0, npc->getPosition().y - attackDistance);
    int endY = std::min(this->getFieldSize() - 1, npc->getPosition().y + attackDistance);

    for (int nx = startX; nx <= endX; ++nx)
    {
        for (int ny = startY; ny <= endY; ++ny)
        {
            auto target = getNPC(nx, ny);
            if (target && target != npc)
            {
                int dx = nx - npc->getPosition().x;
                int dy = ny - npc->getPosition().y;
                int squaredDistance = dx * dx + dy * dy;
                if (squaredDistance <= attackDistance * attackDistance)
                {
                    targets.push_back(target);
                }
            }
        }
    }
}
