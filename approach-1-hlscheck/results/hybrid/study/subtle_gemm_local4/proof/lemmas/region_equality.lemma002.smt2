; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x430660 (bvmul arg0_1 arg1_6)))
(let ((?x14631 (bvmul (_ bv4294967295 32) ?x430660)))
(let ((?x502367 (bvmul arg0_1 arg1_7)))
(let ((?x459481 (bvadd ?x502367 ?x14631)))
(and (distinct ?x459481 (_ bv0 32)) true))))))
(check-sat)
