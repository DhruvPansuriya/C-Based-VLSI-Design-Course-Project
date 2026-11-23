; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_18 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x2588 (bvmul arg0_18 arg2_5)))
(let ((?x726168 (bvmul (_ bv4294967295 32) ?x2588)))
(let ((?x26 (bvmul arg0_18 arg2_4)))
(let ((?x722067 (bvadd ?x26 ?x726168)))
(and (distinct ?x722067 (_ bv0 32)) true))))))
(check-sat)
