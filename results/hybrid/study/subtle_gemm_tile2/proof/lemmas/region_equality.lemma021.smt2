; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x14631 (bvmul arg0_10 arg1_10)))
(let ((?x470502 (bvmul (_ bv4294967295 32) ?x14631)))
(let ((?x265010 (bvmul arg0_10 arg1_11)))
(let ((?x34800 (bvadd ?x265010 ?x470502)))
(and (distinct ?x34800 (_ bv0 32)) true))))))
(check-sat)
