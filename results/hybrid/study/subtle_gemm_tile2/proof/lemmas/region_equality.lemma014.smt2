; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x727367 (bvmul arg0_5 arg1_6)))
(let ((?x588450 (bvmul (_ bv4294967295 32) ?x727367)))
(let ((?x426442 (bvmul arg0_5 arg1_7)))
(let ((?x350800 (bvadd ?x426442 ?x588450)))
(and (distinct ?x350800 (_ bv0 32)) true))))))
(check-sat)
