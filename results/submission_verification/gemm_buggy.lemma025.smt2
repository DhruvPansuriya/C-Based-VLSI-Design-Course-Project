; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x170 (bvmul arg0_10 arg1_2)))
(let ((?x11670 (bvmul (_ bv4294967295 32) ?x170)))
(let ((?x220 (bvmul arg0_10 arg1_8)))
(let ((?x74 (bvadd ?x220 ?x11670)))
(and (distinct ?x74 (_ bv0 32)) true))))))
(check-sat)
