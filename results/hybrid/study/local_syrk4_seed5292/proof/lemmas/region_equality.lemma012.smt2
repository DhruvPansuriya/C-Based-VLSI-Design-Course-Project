; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(assert
 (let ((?x578478 (bvmul arg0_11 arg0_2)))
(let ((?x360014 (bvmul (_ bv4294967295 32) ?x578478)))
(let ((?x505343 (bvmul arg0_14 arg0_2)))
(let ((?x444396 (bvadd ?x505343 ?x360014)))
(and (distinct ?x444396 (_ bv0 32)) true))))))
(check-sat)
