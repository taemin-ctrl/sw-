#include<iostream>
#include<time.h>

using namespace std;

enum main_menu {
    mm_none,
    mm_map,
    mm_store,
    mm_inventory,
    mm_exit
};
enum map_type {
    mt_none,
    mt_easy,
    mt_normal,
    mt_hard,
    mt_back
};

enum job {
    job_none,
    job_knight,
    job_archor,
    job_wizard,
    job_back
};

enum battle {
    battle_none,
    battle_attack,
    battle_back
};

enum item_type {
    it_none,
    it_weapon,
    it_armor,
    it_back
};

enum store_menu {
    sm_none,
    sm_weapon,
    sm_armor,
    sm_back
};

enum equip {
    eq_weapon,
    eq_armor,
    eq_max
};

#define name_size 32
#define item_length 512
#define inventory_max 20
#define stor_weapon_max 3
#define store_armor_max 3
#define level_max 10



struct tagitem {
    char strname[name_size];
    char strtypename[name_size];
    item_type etype;
    int min;
    int max;
    int price;
    int sell;
    char strdesc[item_length];

};

struct taginventory {
    tagitem titem[inventory_max];
    int itemcount;
    int gold;
};

struct tagplayer {
    char strname[name_size];
    char strjobname[name_size];
    job ejob;
    int attackmin;
    int attackmax;
    int armormax;
    int armormin;
    int hp;
    int hpmax;
    int mpmax;
    int mp;
    int exp;
    int level;
    tagitem tequip[eq_max];
    bool bequip[eq_max];
    taginventory tinventory;

};

struct tagmonster {
    char strname[name_size];
    int attackmin;
    int attackmax;
    int armormax;
    int armormin;
    int hp;
    int hpmax;
    int mpmax;
    int mp;
    int level;
    int goldmin;
    int goldmax;
    int iexp;
};

struct taglevelupstatus {
    int attackmin;
    int attackmax;
    int armormin;
    int armormax;
    int hpmin;
    int hpmax;
    int mpmin;
    int mpmax;
};
int main() {
    srand((unsigned int)time(0));

    const int levelupexp[level_max] = { 4000,10000,20000,350000,50000,70000,100000,120000,150000,180000 };
    taglevelupstatus lvuptable[job_back - 1] = {};

    lvuptable[job_knight - 1].attackmin = 4;
    lvuptable[job_knight - 1].attackmax = 10;
    lvuptable[job_knight - 1].armormin = 8;
    lvuptable[job_knight - 1].armormax = 16;
    lvuptable[job_knight - 1].hpmin = 50;
    lvuptable[job_knight - 1].hpmax = 100;
    lvuptable[job_knight - 1].mpmin = 10;
    lvuptable[job_knight - 1].mpmax = 20;

    lvuptable[job_archor - 1].attackmin = 4;
    lvuptable[job_archor - 1].attackmax = 10;
    lvuptable[job_archor - 1].armormin = 8;
    lvuptable[job_archor - 1].armormax = 16;
    lvuptable[job_archor - 1].hpmin = 50;
    lvuptable[job_archor - 1].hpmax = 100;
    lvuptable[job_archor - 1].mpmin = 10;
    lvuptable[job_archor - 1].mpmax = 20;

    lvuptable[job_wizard - 1].attackmin = 4;
    lvuptable[job_wizard - 1].attackmax = 10;
    lvuptable[job_wizard - 1].armormin = 8;
    lvuptable[job_wizard - 1].armormax = 16;
    lvuptable[job_wizard - 1].hpmin = 50;
    lvuptable[job_wizard - 1].hpmax = 100;
    lvuptable[job_wizard - 1].mpmin = 10;
    lvuptable[job_wizard - 1].mpmax = 20;

    tagplayer tplayer = {};

    cout << "이름: ";
    cin.getline(tplayer.strname, name_size - 1);
    int ijob = job_none;
    while (ijob == job_none) {
        system("cls");
        cout << "1. 기사" << endl;
        cout << "2. 궁수" << endl;
        cout << "3. 마법사" << endl;
        cout << "직업을 선택하시오: " << endl;
        cin >> ijob;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (ijob <= job_none || ijob > job_back)
            ijob = job_none;

        tplayer.level = 1;
        tplayer.exp = 0;
        tplayer.ejob = (job)ijob;
        tplayer.tinventory.gold = 10000;


        switch (tplayer.ejob) {
        case job_knight:
            strcpy_s(tplayer.strjobname, "기사");
            tplayer.attackmin = 5;
            tplayer.attackmax = 10;
            tplayer.armormin = 15;
            tplayer.armormax = 20;
            tplayer.hpmax = 500;
            tplayer.hp = 500;
            tplayer.mp = 100;
            tplayer.mpmax = 100;
            break;
        case job_archor:
            strcpy_s(tplayer.strjobname, "궁수");
            tplayer.attackmin = 5;
            tplayer.attackmax = 10;
            tplayer.armormin = 15;
            tplayer.armormax = 20;
            tplayer.hpmax = 500;
            tplayer.hp = 500;
            tplayer.mp = 100;
            tplayer.mpmax = 100;
            break;
        case job_wizard:
            strcpy_s(tplayer.strjobname, "마법사");
            tplayer.attackmin = 5;
            tplayer.attackmax = 10;
            tplayer.armormin = 15;
            tplayer.armormax = 20;
            tplayer.hpmax = 500;
            tplayer.hp = 500;
            tplayer.mp = 100;
            tplayer.mpmax = 100;
            break;
        }
    }
    tagmonster tmonster[mt_back - 1] = {};
    strcpy_s(tmonster[0].strname, "고블린");
    tmonster[0].attackmax = 15;
    tmonster[0].attackmin = 5;
    tmonster[0].armormax = 2;
    tmonster[0].armormin = 5;
    tmonster[0].hp = 7;
    tmonster[0].hpmax = 7;
    tmonster[0].mp = 15;
    tmonster[0].mpmax = 15;
    tmonster[0].goldmax = 700;
    tmonster[0].goldmin = 400;
    tmonster[0].iexp = 1000;
    tmonster[0].level = 1;

    strcpy_s(tmonster[0].strname, "트롤");
    tmonster[1].attackmax = 20;
    tmonster[1].attackmin = 10;
    tmonster[1].armormax = 2;
    tmonster[1].armormin = 5;
    tmonster[1].hp = 10;
    tmonster[1].hpmax = 10;
    tmonster[0].mp = 20;
    tmonster[0].mpmax = 20;
    tmonster[1].goldmax = 1000;
    tmonster[1].goldmin = 500;
    tmonster[1].iexp = 1000;
    tmonster[1].level = 1;

    strcpy_s(tmonster[2].strname, "드래곤");
    tmonster[2].attackmax = 20;
    tmonster[2].attackmin = 10;
    tmonster[2].armormax = 2;
    tmonster[2].armormin = 5;
    tmonster[2].hp = 10;
    tmonster[2].hpmax = 10;
    tmonster[0].mp = 20;
    tmonster[0].mpmax = 20;
    tmonster[2].goldmax = 1000;
    tmonster[2].goldmin = 500;
    tmonster[2].iexp = 1000;
    tmonster[2].level = 1;

    tagitem tstoreweapon[stor_weapon_max] = {};
    tagitem tstorearmor[store_armor_max] = {};

    while (1) {
        system("cls");
        cout << "1.맵" << endl;
        cout << "2.상점" << endl;
        cout << "3.가방" << endl;
        cout << "4.종료" << endl;
        cout << "메뉴를 선택하시오: " << endl;

        int imenu;
        cin >> imenu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }

        if (imenu == mm_exit)
            break;

        switch (imenu) {
        case mm_map:
            while (1) {
                system("cls");
                cout << "1. 쉬움" << endl;
                cout << "2. 보통" << endl;
                cout << "3.어려움" << endl;
                cout << "4.뒤로 가기" << endl;
                cout << "맵을 선택하시오: " << endl;
                cin >> imenu;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
                if (imenu == mt_back)
                    break;
                tagmonster tmonst = tmonster[imenu - 1];
                while (1) {
                    system("cls");
                    switch (imenu) {
                    case mt_easy:
                        cout << "쉬움" << endl;
                        break;
                    case mt_normal:
                        cout << "보통" << endl;
                        break;
                    case mt_hard:
                        cout << "어려움" << endl;
                        break;
                    }
                    cout << "player" << endl;
                    cout << "이름: " << tplayer.strname << "\t직업: " <<
                        tplayer.strjobname << endl;
                    cout << "레벨: " << tplayer.level << "\t경험치: " <<
                        tplayer.exp << "/" << levelupexp[tplayer.level - 1] << endl;

                    if (tplayer.bequip[eq_weapon] == true) {
                        cout << " 공격력: " << tplayer.attackmin << "-" <<
                            tplayer.attackmax << "+" << tplayer.tequip[eq_weapon].max;
                    }

                    else {
                        cout << " 공격력: " << tplayer.attackmin << "-" <<
                            tplayer.attackmax;
                    }

                    if (tplayer.bequip[eq_armor] == true) {
                        cout << " 방어력: " << tplayer.armormin << "-" <<
                            tplayer.armormax << "+" << tplayer.tequip[eq_armor].max;
                    }

                    else {
                        cout << " 방어력: " << tplayer.armormin << "-" <<
                            tplayer.armormax << endl;
                    }
                    cout << "체력: " << tplayer.hp << "/" << tplayer.hpmax <<
                        "\t마나" << tplayer.mp << "/" << tplayer.mpmax << endl;

                    if (tplayer.bequip[eq_weapon] == true) {
                        cout << " 공격력: " << tplayer.attackmin << "-" <<
                            tplayer.attackmax << "+" << tplayer.tequip[eq_weapon].max;
                    }

                    else {
                        cout << " 공격력: " << tplayer.attackmin << "-" <<
                            tplayer.attackmax;
                    }

                    if (tplayer.bequip[eq_armor] == true) {
                        cout << " 방어력: " << tplayer.armormin << "-" <<
                            tplayer.armormax << "+" << tplayer.tequip[eq_armor].max;
                    }

                    else {
                        cout << " 방어력: " << tplayer.armormin << "-" <<
                            tplayer.armormax << endl;
                    }

                    cout << "보유골드: " << tplayer.tinventory.gold << " gold" << endl << endl;

                    cout << "monster" << endl;
                    cout << "이름: " << tmonst.strname << "\t레벨: " <<
                        tmonst.level << endl;

                    cout << "공격력: " << tplayer.attackmin << "-" <<
                        tmonst.attackmax << "\t방어력: " << tmonst.armormin
                        << "-" << tmonst.armormax << endl;
                    cout << "체력: " << tmonst.hp << "/" << tmonst.hpmax <<
                        "\t마나" << tmonst.mp << "/" << tmonst.mpmax << endl;
                    cout << "획득 경험치: " << tmonst.iexp << "\t획득 골드: " <<
                        tmonst.goldmin << " -" << tmonst.goldmax << endl << endl;;

                    cout << "1. 공격" << endl;
                    cout << "2. 도망가기" << endl;
                    cout << "메뉴를 선택하시오: " << endl;
                    cin >> imenu;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }

                    else if (imenu == battle_back)
                        break;

                    switch (imenu) {
                    case battle_attack: {
                        int attackmin = tplayer.attackmin;
                        int attackmax = tplayer.armormax;

                        if (tplayer.bequip[eq_weapon]) {
                            attackmin += tplayer.tequip[eq_weapon].min;
                            attackmax += tplayer.tequip[eq_weapon].max;
                        }

                        int attack = rand() % (tplayer.attackmax - tplayer.attackmin + 1) +
                            tplayer.attackmin;
                        int armor = rand() % (tmonst.armormax - tmonst.armormin + 1) +
                            tmonst.armormin;

                        int damage = attack - armor;
                        damage = damage < 1 ? 1 : damage;

                        tmonst.hp -= damage;

                        cout << tplayer.strname << " 가 " << tmonst.strname <<
                            " 에게 " << damage << "피해를 입혔습니다." << endl;

                        if (tmonst.hp <= 0) {
                            cout << tmonst.strname << " 몬스터가 사망했습니다." << endl;

                            tplayer.exp += tmonst.iexp;
                            int gold = (rand() % (tmonst.goldmax - tmonst.goldmin + 1) +
                                tmonst.goldmin);
                            tplayer.tinventory.gold += gold;

                            cout << tmonst.iexp << "경험치를 획득했습니다." << endl;
                            cout << gold << " gold를 획득하였습니다." << endl;

                            tmonst.hp = tmonst.hpmax;
                            tmonst.mp = tmonst.mpmax;

                            if (tplayer.exp >= levelupexp[tplayer.level - 1]) {
                                tplayer.exp -= levelupexp[tplayer.level - 1];

                                ++tplayer.level;

                                cout << "레벨 업을 하였습니다." << endl;

                                int jobindex = tplayer.ejob - 1;
                                int attackup = rand() % (lvuptable[jobindex].attackmax - lvuptable[jobindex].attackmin + 1) +
                                    lvuptable[jobindex].attackmin;
                                int armorup = rand() % (lvuptable[jobindex].armormax - lvuptable[jobindex].armormin + 1) +
                                    lvuptable[jobindex].armormin;
                                int hpup = rand() % (lvuptable[jobindex].hpmax - lvuptable[jobindex].hpmin + 1) +
                                    lvuptable[jobindex].hpmin;
                                int mpup = rand() % (lvuptable[jobindex].mpmax - lvuptable[jobindex].mpmin + 1) +
                                    lvuptable[jobindex].mpmin;

                                tplayer.attackmin += lvuptable[jobindex].attackmin;
                                tplayer.attackmax += lvuptable[jobindex].attackmax;
                                tplayer.armormin += lvuptable[jobindex].armormin;
                                tplayer.armormax += lvuptable[jobindex].armormax;

                                tplayer.hpmax += hpup;
                                tplayer.mpmax += mpup;

                                tplayer.hp = tplayer.hpmax;
                                tplayer.mp = tplayer.mpmax;
                            }
                        }
                        attack = rand() % (tmonst.attackmax - tmonst.attackmin + 1) +
                            tmonst.attackmin;
                        armor = rand() % (tplayer.armormax - tplayer.armormin + 1) +
                            tplayer.armormin;

                        int armormin = tplayer.armormin;
                        int armormax = tplayer.armormax;

                        if (tplayer.bequip[eq_armor]) {
                            armormin += tplayer.tequip[eq_armor].min;
                            armormax += tplayer.tequip[eq_armor].max;

                        }
                        damage = attack - armor;
                        damage = damage < 1 ? 1 : damage;

                        cout << tmonst.strname << " 가" << tplayer.strname <<
                            "에게 " << damage << "피해를 입혔습니다." << endl;

                        tplayer.hp -= damage;
                        if (tplayer.hp <= 0) {
                            cout << tplayer.strname << " 플레이어가 사망했습니다." << endl;

                            int exp = tplayer.exp * 0.1f;
                            int gold = tplayer.tinventory.gold * 0.1f;

                            tplayer.exp -= exp;
                            tplayer.tinventory.gold -= gold;

                            cout << exp << " 경험치를 잃었습니다." << endl;
                            cout << gold << " gold를 잃었습니다." << endl;

                            tplayer.hp = tplayer.hpmax;
                            tplayer.mp = tplayer.mpmax;
                        }
                        system("pause");

                    }


                                      break;
                    }
                }
                break;
            }

        case mm_store:
            while (1) {
                system("cls");
                cout << "상점" << endl;
                cout << "1.무기 상점" << endl;
                cout << "2. 방어구 상점" << endl;
                cout << "3. 뒤로 가기" << endl;
                cout << "상점을 선택하시오: " << endl;
                cin >> imenu;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\t');
                    continue;
                }
                else if (imenu == sm_back)
                    break;

                switch (imenu) {
                case sm_weapon:
                    while (1) {
                        system("cls");
                        cout << "무기상점" << endl;


                        for (int i = 0; i < stor_weapon_max; ++i) {
                            switch (i) {
                            case 0:
                                cout << i + 1 << " 이름 : 별볼일 없는 완드" << tstoreweapon[i].strname <<
                                    "\t종류: " << tstoreweapon[i].strtypename << endl;
                                cout << "공격력 : 800" << tstoreweapon[i].min << "-" <<
                                    tstoreweapon[i].max << endl;
                                cout << "판매가격 : 1100" << tstoreweapon[i].price << "\t구매가격 : " <<
                                    tstoreweapon[i].sell << endl;
                                cout << "설명: 그럭저럭 쓸만한 완드" << tstoreweapon[i].strdesc << endl << endl;
                                break;
                            case 1:
                                cout << i + 1 << " 이름 : 개쩌는 완드" << tstoreweapon[i].strname <<
                                    "\t종류: " << tstoreweapon[i].strtypename << endl;
                                cout << "공격력 : 1000" << tstoreweapon[i].min << "-" <<
                                    tstoreweapon[i].max << endl;
                                cout << "판매가격 : 1500" << tstoreweapon[i].price << "\t구매가격 : " <<
                                    tstoreweapon[i].sell << endl;
                                cout << "설명: 개쩐다" << tstoreweapon[i].strdesc << endl << endl;
                                break;
                            case 2:
                                cout << i + 1 << " 이름 : 왕도의 완드" << tstoreweapon[i].strname <<
                                    "\t종류: " << tstoreweapon[i].strtypename << endl;
                                cout << "공격력 : 3000" << tstoreweapon[i].min << "-" <<
                                    tstoreweapon[i].max << endl;
                                cout << "판매가격 : 3000" << tstoreweapon[i].price << "\t구매가격 : " <<
                                    tstoreweapon[i].sell << endl;
                                cout << "설명: 개쩐다" << tstoreweapon[i].strdesc << endl << endl;
                                break;
                            }
                            
                        }
                        cout << stor_weapon_max + 1 << ". 뒤로 가기" << endl;
                        cout << "보유금액: " << tplayer.tinventory.gold << "gold" << endl;
                        cout << "남은 공간: " << inventory_max - tplayer.tinventory.itemcount << endl;
                        cout << "구입할 아이템을 선택하시오: ";
                        cin >> imenu;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        else if (imenu == stor_weapon_max + 1) {
                            break;
                        }
                        else if (imenu<1 || imenu>stor_weapon_max + 1) {
                            cout << "잘못 선택하였습니다." << endl;
                            system("pause");
                            continue;
                        }
                        int weaponindex = imenu - 1;

                        if (tplayer.tinventory.itemcount == inventory_max) {
                            cout << "가방이 꽉 찼습니다." << endl;
                            system("pause");
                            continue;
                        }
                        else if (tplayer.tinventory.gold < tstoreweapon[weaponindex].price) {
                            cout << "보유 금액이 부족합니다." << endl;
                            system("pause");
                            continue;
                        }

                        tplayer.tinventory.titem[tplayer.tinventory.itemcount] =
                            tstoreweapon[weaponindex];
                        ++tplayer.tinventory.itemcount;

                        tplayer.tinventory.gold -= tstoreweapon[weaponindex].price;

                        cout << tstoreweapon[weaponindex].strname << "아이템을 구매하였습니다." << endl;
                        system("pause");
                    }
                    break;
                case sm_armor:
                    while (1) {
                        system("cls");
                        cout << "방어구 상점" << endl;
                        for (int i = 0; i < store_armor_max; ++i) {
                            cout << i + 1 << " 이름 : " << tstorearmor[i].strname <<
                                "\t종류: " << tstorearmor[i].strtypename << endl;
                            cout << "공격력 : " << tstorearmor[i].min << "-" <<
                                tstorearmor[i].max << endl;
                            cout << "판매가격 : " << tstorearmor[i].price << "\t구매가격 : " <<
                                tstorearmor[i].sell << endl;
                            cout << "설명: " << tstorearmor[i].strdesc << endl << endl;
                        }
                        cout << store_armor_max + 1 << ". 뒤로 가기" << endl;
                        cout << "보유금액: " << tplayer.tinventory.gold << "gold" << endl;
                        cout << "남은 공간: " << inventory_max - tplayer.tinventory.itemcount << endl;
                        cout << "구입할 아이템을 선택하시오: ";
                        cin >> imenu;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        else if (imenu == store_armor_max + 1) {
                            break;
                        }
                        else if (imenu<1 || imenu>store_armor_max + 1) {
                            cout << "잘못 선택하였습니다." << endl;
                            system("pause");
                            continue;
                        }
                        int armorindex = imenu - 1;

                        if (tplayer.tinventory.itemcount == inventory_max) {
                            cout << "가방이 꽉 찼습니다." << endl;
                            system("pause");
                            continue;
                        }
                        else if (tplayer.tinventory.gold < tstoreweapon[armorindex].price) {
                            cout << "보유 금액이 부족합니다." << endl;
                            system("pause");
                            continue;
                        }

                        tplayer.tinventory.titem[tplayer.tinventory.itemcount] =
                            tstorearmor[armorindex];
                        ++tplayer.tinventory.itemcount;

                        tplayer.tinventory.gold -= tstorearmor[armorindex].price;

                        cout << tstorearmor[armorindex].strname << "아이템을 구매하였습니다." << endl;
                        system("pause");
                    }
                    break;
                }
            }
            break;

        case mm_inventory:
            while (1) {
                system("cls");
                cout << "인벤토리" << endl;
                cout << "player" << endl;
                cout << "이름: " << tplayer.strname << "\t직업: " <<
                    tplayer.strjobname << endl;
                cout << "레벨: " << tplayer.level << "\t경험치: " <<
                    tplayer.exp << endl;

                if (tplayer.bequip[eq_weapon] == true) {
                    cout << " 공격력: " << tplayer.attackmin << "-" <<
                        tplayer.attackmax << "+" << tplayer.tequip[eq_weapon].max;
                }

                else {
                    cout << " 공격력: " << tplayer.attackmin << "-" <<
                        tplayer.attackmax;
                }

                if (tplayer.bequip[eq_armor] == true) {
                    cout << " 방어력: " << tplayer.armormin << "-" <<
                        tplayer.armormax << "+" << tplayer.tequip[eq_armor].max;
                }

                else {
                    cout << " 방어력: " << tplayer.armormin << "-" <<
                        tplayer.armormax << endl;
                }
                cout << "공격력: " << tplayer.attackmin << "-" <<
                    tplayer.attackmax << "\t방어력: " << tplayer.armormin
                    << "-" << tplayer.armormax << endl;
                cout << "체력: " << tplayer.hp << "/" << tplayer.hpmax <<
                    "\t마나" << tplayer.mp << "/" << tplayer.mpmax << endl;

                if (tplayer.bequip[eq_weapon])
                    cout << "장착무기: " << tplayer.tequip[eq_weapon].strname;
                else
                    cout << "장착무기 : 없음.";

                if (tplayer.bequip[eq_armor])
                    cout << "장착방어구: " << tplayer.tequip[eq_armor].strname;
                else
                    cout << "장착방어구 : 없음." << endl;

                cout << "보유골드: " << tplayer.tinventory.gold << " gold" << endl << endl;
                for (int i = 0; i < tplayer.tinventory.itemcount; ++i) {
                    cout << i + 1 << " 이름 : " << tplayer.tinventory.titem[i].strname <<
                        "\t종류: " << tplayer.tinventory.titem[i].strtypename << endl;
                    cout << "공격력 : " << tplayer.tinventory.titem[i].min << "-" <<
                        tplayer.tinventory.titem[i].max << endl;
                    cout << "판매가격 : " << tplayer.tinventory.titem[i].price << "\t구매가격 : " <<
                        tplayer.tinventory.titem[i].sell << endl;
                    cout << "설명: " << tplayer.tinventory.titem[i].strdesc << endl << endl;
                }
                cout << tplayer.tinventory.itemcount + 1 << ". 뒤로 가기" << endl;
                cout << "장착할 아이템을 선택하시오: ";
                cin >> imenu;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }

                else if (imenu == tplayer.tinventory.itemcount + 1)
                    break;

                else if (imenu<1 || imenu>tplayer.tinventory.itemcount + 1) {
                    cout << "잘못 선택하였습니다." << endl;
                    system("pause");
                    continue;
                }

                int idx = imenu - 1;

                equip eq;

                switch (tplayer.tinventory.titem[idx].etype) {
                case it_weapon:
                    eq = eq_weapon;
                    break;
                case it_armor:
                    eq = eq_armor;
                    break;
                }

                if (tplayer.bequip[eq] == true) {
                    tagitem tswap = tplayer.tequip[eq];
                    tplayer.tequip[eq] = tplayer.tinventory.titem[idx];
                    tplayer.tinventory.titem[idx] = tswap;
                }
                else {
                    tplayer.tequip[eq] = tplayer.tinventory.titem[idx];

                    for (int i = idx; i < tplayer.tinventory.itemcount - 1; ++i) {
                        tplayer.tinventory.titem[i] = tplayer.tinventory.titem[i + 1];
                    }
                    --tplayer.tinventory.itemcount;

                    tplayer.bequip[eq] = true;
                }
                cout << tplayer.tequip[eq].strname << "아이템을 장착했습니다." << endl;
                system("pause");
                break;
            }

        default:
            cout << "잘못 선택하셨습니다." << endl;
            break;
        }
    }

    return 0;
}
